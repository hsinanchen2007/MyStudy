### 解题思路
mark一下
![image.png](https://pic.leetcode-cn.com/94f9125bc9ea89ac9b3cf4aeb2878020ab3337c94cf7c1c4b577900336d4b2bb-image.png)

思路和用快排求第k大的元素类似，在fastSort方法中，我们并不对每一个元素都进行排序，只需要判断一下分区点和k的值的关系
如果k >p+1 说明 分区点左右的都不需要排序了 因为他们的和小于k



### 代码

```java
class Solution {
    
   public int[] getLeastNumbers(int [] input, int k) {
        fastSort(input,0,input.length-1,k);
        int[] res = new int[k];
        for(int i = 0 ;i< k;i++){
            res[i] = input[i];
        }
        return res;
    }
    
    private void fastSort(int[] a,int s,int e,int k){
        if(s > e)return;
        int p = partation(a,s,e);
        if(p+1 == k){
            return;
        }else if(p+1 < k){
            fastSort(a,p+1,e,k);
        }else{
            fastSort(a,s,p-1,k);
        }
    }
    
    private int partation(int[] a,int s ,int e){
        int privot = a[e];//取最后一个数作为分区点
        int i = s;
        for(int j = s;j < e;j++){
            if(a[j] < privot){
                swap(a,i,j);
                i++;
            }
        }
        swap(a,i,e);
      return i;
    }
    
    private void swap(int[] a ,int i ,int j){
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    } 
}
```