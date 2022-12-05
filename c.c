#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList1(struct ListNode* head) {
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = head->next;   //当head==NULL,这里next直接非法访问
                                        //所以开头加入判断

    while (n2)
    {
        //  翻转
        n2->next = n1;
        //  迭代向后走
        n1 = n2;
        n2 = n3;
        if (n3) // 判断n3是否为NULL，为NULL则不执行
            n3 = n3->next;
    }
    return n1;
}

struct ListNode* reverseList2(struct ListNode* head) {
    struct ListNode* cur, *next, *newhead;
    cur = head; next = head->next;  newhead = NULL;

    while (cur)
    {
        //  头插
        cur->next = newhead;
        newhead = cur;
        //  迭代
        cur = next;
        if (next)
            next = next->next;
    }

    return newhead;
}
int main()
{
    //  自己创建链表
    struct ListNode* newnode1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode4 = (struct ListNode*)malloc(sizeof(struct ListNode));

    //  给链表赋值
    newnode1->val = 1; newnode1->next = newnode2;
    newnode2->val = 2; newnode2->next = newnode3;
    newnode3->val = 3; newnode3->next = newnode4;
    newnode4->val = 4; newnode4->next = NULL;

    //  调用链表函数
    struct ListNode* head = reverseList2(newnode1);
    return 0;
}