#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define ROOT_VALUE 1000
typedef int TElemType;
typedef int Status;
int arr[10001];

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lChild, *rChild;
} BiTNode;

BiTNode* makeNode(TElemType e)
{
    BiTNode* temp = (BiTNode*)malloc(sizeof(BiTNode));
    temp->lChild = temp->rChild = NULL;
    temp->data = e;
    return temp;
}

Status initBitTree(BiTNode *t)
{
    t->data = ROOT_VALUE;
    t->lChild = t->rChild = NULL;
    return OK;
}

Status insertNode(BiTNode* t, TElemType e)
{
    if(t== NULL) {
        return ERROR;
    }
    if(e < (t->data))
    {
        if(t->lChild == NULL) {
            t->lChild = makeNode(e);
            return OK;
        } else {
            insertNode(t->lChild, e);
        }
    } else {
        if(t->rChild == NULL) {
            t->rChild = makeNode(e);
            return OK;
        } else {
            insertNode(t->rChild, e);
        }
    }
    return OK;
}

Status inOrderTraverse(BiTNode* t, Status (*visit)(TElemType e))
{
    if(t) {
        if(inOrderTraverse(t->lChild, visit))
            if(visit(t->data))
                if(inOrderTraverse(t->rChild, visit)) return OK;
    return ERROR;
    }
    return OK;
}

Status printData(TElemType e)
{
    printf("%d ", e);
    return OK;
}

int sum(BiTNode* t)
{
    long long total = 0;
    if(t != NULL)
    {
        total += sum(t->lChild);
        total += t->data;
        total += sum(t->rChild);
    }
    return total;
}

int main(int argc, char const *argv[])
{
    int i,n,a;
    scanf("%d",&n);
    for(a = 0; a < n; a++)
    {
        scanf("%d", &arr[a]);
    }
    BiTNode t;
    initBitTree(&t);
    for (i = 0; i < n; i++)
    {
        insertNode(&t, arr[i]);
    }
    inOrderTraverse(&t, printData);
    printf("\n");
    printf("%d", sum(&t));
    return 0;
}
