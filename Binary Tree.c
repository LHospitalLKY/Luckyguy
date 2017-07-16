#include<stdio.h>
#include<stdlib.h>
#include"/home/lhospital/progamma/CPROGRAMMA/数据结构文件集/status.h"
#define Max 50

/*二叉链表结构体*/
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


BiTree CreateBiTree(BiTree &T); /*二叉链表的先序建立*/
void PreOrde(BiTree T);     /*先序法遍历二叉树*/
void InOrde(BiTree T);      /*中序法遍历二叉树*/
void PostOrde(BiTree T);    /*后序法遍历二叉树*/
void InOrdeTraver(BiTree T);    /*非递归中序遍历法*/
void PreOrdeTraver(BiTree T);   /*非递归前序遍历法*/
void PostOrdeTraver(BiTree T);  /*非递归后序遍历法*/


int main()
{
    BiTree T;
    printf("Please input the Binary Tree:\n");
    T = CreateBiTree(T);
    PreOrde(T);
    printf("\n");
    InOrde(T);
    printf("\n");
    PostOrde(T);
    printf("\n");
    InOrdeTraver(T);
    printf("\n");
    PreOrdeTraver(T);
    printf("\n");
    PostOrdeTraver(T);

    getchar();
    getchar();
    return 1;
}

/*二叉链表的递归先序建立*/
BiTree CreateBiTree(BiTree &T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        T = 0;
    else
    {
        if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))
            exit(Over);
        T -> data = ch;
        CreateBiTree(T -> lchild);
        CreateBiTree(T -> rchild);
    }
    return T;
}
/*二叉树递归前序遍历*/
void PreOrde(BiTree T)
{
    if (T != NULL)
    {
        printf("%c", T -> data);
        PreOrde(T -> lchild);
        PreOrde(T -> rchild);
    }
}
/*递归中序遍历*/
void InOrde(BiTree T)
{
    if (T != NULL)
    {
        InOrde(T -> lchild);
        printf("%c", T -> data);
        InOrde(T -> rchild);
    }
}
/*递归后序遍历*/
void PostOrde(BiTree T)
{
    if (T != NULL)
    {
        PostOrde(T -> lchild);
        PostOrde(T -> rchild);
        printf("%c", T -> data);
    }
}
/*中序遍历的非递归算法*/
void InOrdeTraver(BiTree T)
{
    BiTree M[Max], p;
    p = T;
    int i = -1;
    int k = 1;

    do{
        while (p != NULL)
        {
            M[++i] = p;
            p = p -> lchild;
        }
        k++;
        p = M[i--];
        printf("%c",p -> data);
        p = p -> rchild;
    } while(!(p == NULL && i == -1));
}
/*前序遍历非递归算法*/
void PreOrdeTraver(BiTree T)
{
    BiTree M[Max], p;
    p = T;
    int t = -1;

    do{
        while(p != NULL)
        {
            printf("%c", p -> data);
            M[++t] = p;
            p = p -> lchild;            
        }
        p = M[t--];
        p = p -> rchild;
    }while(!(p == NULL && t == -1));
}
/*后序遍历非递归算法*/
void PostOrdeTraver(BiTree T)
{
    BiTree M1[Max], p;
    int M2[Max], flag, top;

    p = T;
    top = -1;
    
    if (T != NULL)
    {
        do{
            while (p != NULL)
            {
                M1[++top] = p;
                M2[top] = 0;
                p = p -> lchild;
            }

            p = M1[top];
            flag = M2[top--];
            if (flag == 0)
            {
                M1[++top] = p;
                M2[top] = 1;
                p = p -> rchild;
            }
            else
            {
                printf("%c",p -> data);
                p = NULL;
            }

        }while (!(p == NULL && top == -1));
    }
}
