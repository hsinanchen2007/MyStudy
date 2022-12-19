### 解题思路
1.建立Hash表，Hash函数为num%10099(必须余一个素数)，用链地址法处理冲突
2.每个nums中的元素，先在Hash表中查找他的target-nums[i]在不在表中，若在直接返回，否则，就插入到表中

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct node{
     int a;
     int num;
     struct node *next;
 }node,*N;
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
       node *a[10099]; 
      int *s=(int *)malloc(2*sizeof(int));*returnSize=2;
     for(int i=0;i<10099;i++) a[i]=NULL;
      for(int i=0;i<numsSize;i++){
          //先查找
          int k=abs(nums[i])%10099;int z=abs(target-nums[i])%10099;
          N n1=a[z];
          while(n1!=NULL){
              if(n1->a==target-nums[i]){
                  s[0]=n1->num;s[1]=i;return s;
              }
              n1=n1->next;
          }
          //后插入
          N n2=(N)malloc(sizeof(node));
          N n3=a[k];
          n2->a=nums[i];
          n2->num=i;
          n2->next=NULL;
          if(n3==NULL) a[k]=n2;
           else {
              while(n3->next!=NULL) n3=n3->next;
              n3->next=n2;
           }
      }
      return s;
}













```