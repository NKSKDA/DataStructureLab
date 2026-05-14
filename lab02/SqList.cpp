#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAXLEN 100
int Error = 0;
// 结构体定义
typedef struct SqList
{
    int data[MAXLEN];
    int length;
} SqList;
// 顺序表的创建
void CreateList(SqList *&list)
{
    list = (SqList *)malloc(sizeof(SqList));
    list->length = 0;
}
// 顺序表的查找
int GetElem(SqList *list, int index)
{
    int i = 0;
    if(index<0||index>list->length-1)return -1;
    else return list->data[index-1];
}
// 顺序表的插入函数
int ListInsert(SqList *list, int index, int data)
{
    int j;
    if (index < 1 || index > list->length + 1 || list->length == MAXLEN)
    {
        return -2;
    }
    index--;
    for (j = list->length; j > index; j--)
    {
        list->data[j] = list->data[j - 1];
    }
    list->data[index] = data;
    list->length++;
    return true;
}
// 顺序表的指定位置数据的删除
int ListDelete(SqList *list, int index)
{
    int j;
    if (index < 1 || index > list->length)
    {
        return -3;
    }
    index--;
    for (j = index; j < list->length; j++)
    {
        list->data[j] = list->data[j + 1];
    }
    list->length--;
    return true;
}
// 顺序表打印
void DispList(SqList *list)
{
    for (int i = 0; i < list->length; i++)
    {
        cout << list->data[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;cin>>n;int k;SqList* list=nullptr;int a[MAXLEN];
    CreateList(list);
    //第1行
    for(int i=0;i<n;i++){
        cin>>k;
        list->data[i]=k;
        list->length++;
    }
    DispList(list);
    //第2行
    cin>>k;
    int element=GetElem(list,k);
    if(element==-1)cout<<"Error"<<element<<endl;
    else cout << element<<endl;
    //第3行
    int index,data;
    cin>>index>>data;
    k=ListInsert(list,index,data);
    if(k==-2)cout<<"Error-2"<<endl;
    else DispList(list);
    //第4行
    cin>>index;
    k=ListDelete(list,index);
    if(k==-3)cout<<"Error-3"<<endl;
    else DispList(list);
}