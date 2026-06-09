参考约瑟夫环，建立循环链表，因为翻牌之后剩余的情况，一种逻辑，
约瑟夫的问题在于，每个节点不一定是连续，会丢失节点位置，
为解决这个问题 ， 
我们 想办法 申请到一个环，使得他的位置连续 ，这样就算丢失节点位置，我们依然可以访问

代码如下
#include <stdio.h>
#include <stdlib.h>


 typedef struct node            //建立节点  
 {
    int data ; 
    struct node *previous ;
    struct node *next ; 
 }node; 

int* deckRevealedIncreasing(int* deck, int deckSize){
    node* array=(node*)malloc(sizeof(node)*deckSize) ;   // 申请到一个连续空间  
    int i ;
    int j ; 
    int k ;
    
    
    for(i=0;i<deckSize-1;i++)             // 对牌从小到大 ，顺序排列  
    {
    	for(j=0;j<deckSize-1-i;j++)  
    	{
    		if(deck[j]>deck[j+1])
    		{
    			k=deck[j];  
    			deck[j]=deck[j+1];
    			deck[j+1]= k ;
			}
		}
	}
	
	for(i=0;i<7;i++)               // 检查结果 
	{
		printf("%d ",deck[i]) ; 
	} 
	
	printf("\n") ; 
    
    
    
    
    
    
    for(i=0;i<deckSize-1;i++)                  // 使 申请的节点连成 环  
    {
        array[i].next=array+i+1;
        array[i+1].previous=array+i;
    }
    array[0].previous=array+deckSize-1;
    array[deckSize-1].next=array ;

    node* p=array;
    node* temp ; 
    
    for(i=0;i<deckSize;i++)
    {
        p->data=deck[i];
        temp=p ; 
        p=p->next->next ;
        temp->previous->next=temp->next; 
        
    }
    for(i=0;i<deckSize;i++)             //赋值  
    {
        deck[i]=array[i].data; 
    }
    free(array) ;

    return deck ; 


}

main ()
{
	int deck[7]={2,3,11,13,5,15,7} ;    //  这是给出牌的顺序  
	int i  ; 
	
	

	deckRevealedIncreasing(deck, 7) ;
 
	for( i=0;i<7;i++)
	{
		printf("%d ",deck[i])   ; 
	}
	

} 



看不懂leetcode的传参 有人可以指导我吗



写的比较快 ，完备尚未检查 ， 如错误 ，请指证