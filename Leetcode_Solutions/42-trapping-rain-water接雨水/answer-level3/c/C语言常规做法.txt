该题做得有些吃力，一直觉得代码不好看，内存消耗也较大。未来重新设计算法。（原理图待更）
```c
typedef struct linkedListNode{
    int height;
    int first;
    int last;
    struct linkedListNode* next;
} Node;

int trap(int* height, int heightSize){
    if(heightSize==0) return 0;
    int i=0,sum=0,currentHeight=0;
    Node* top=0;
    while(height[i]==0){
        i++;
        if(i>=heightSize) break;
    }
    while(i<heightSize){
        Node* node=malloc(sizeof(Node));
        node->next=top;
        currentHeight=height[i];
        node->first=i;
        node->height=currentHeight;
        while(height[i]==currentHeight){
            i++;
            if(i>=heightSize) break;
        }
        node->last=i-1;
        if(top){
            while(node->height>top->height){
                if(top->next){
                    sum+=((top->next->height>node->height?node->height:top->next->height)-top->height)*(node->first-top->next->last-1);
                }
                node->next=top->next;
                free(top);
                top=node->next;
                if(top==0) break;
                if(node->height==top->height){
                    node->next=top->next;
                    free(top);
                    top=node;
                }
            }
        }
        top=node;
    }
    return sum;
}
```