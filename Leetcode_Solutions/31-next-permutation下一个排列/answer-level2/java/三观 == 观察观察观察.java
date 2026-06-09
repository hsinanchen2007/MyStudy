# 思路

> 观察一个全排列, 按字典序排序. 发现

- 从后往前遍历, 发现第一个顺序对, $q[i] < q[i+1]$, 记录索引 $start = i$. 说明第i个元素需要将与某个数进行交换. 

- 从后往前遍历, 遍历范围属于 {${i, i+1, \dots n-1}$}. 寻找第一个比 $q[i] < q[m]$ 小的元素, 记录索引 $end = m$.

- 上述两步确认了第`i`个元素与第`m`个元素进行交换. 
- 交换完成第`i`个元素后, 确认 {${i+1, i+2, \dots, n-1}$} 这些数的位置, 翻转这些元素即可. 

# 举个例子

```java
q = [1, 2, 3, 4, 5, 6]
q = [1, 2, 3, 4, 6, 5]
q = [1, 2, 3, 5, 4, 6]
q = [1, 2, 3, 5, 6, 4]
q = [1, 2, 3, 6, 4, 5]
q = [1, 2, 3, 6, 5, 4]
q = [1, 2, 4, 3, 5, 6]
q = [1, 2, 4, 5, 3, 6]
q = [1, 2, 4, 5, 6, 3]
q = [1, 2, 5, 3, 4, 6]
q = [1, 2, 5, 4, 3, 6]
q = [1, 2, 5, 4, 6, 3]
q = [1, 3, 2, 4, 5, 6]
q = [1, 3, 4, 2, 5, 6]
q = [1, 3, 4, 5, 2, 6]
q = [1, 3, 4, 5, 6, 2]
q = [1, 3, 5, 2, 4, 6]
q = [1, 3, 5, 4, 2, 6]
q = [1, 3, 5, 4, 6, 2]
q = [1, 3, 5, 6, 2, 4]
...
q = [6, 5, 1, 2, 3, 4]
q = [6, 5, 2, 1, 3, 4]
q = [6, 5, 2, 3, 1, 4]
q = [6, 5, 2, 3, 4, 1]
q = [6, 5, 2, 4, 1, 3]
q = [6, 5, 2, 4, 3, 1]
q = [6, 5, 3, 1, 2, 4]
q = [6, 5, 3, 2, 1, 4]
q = [6, 5, 3, 2, 4, 1]
q = [6, 5, 3, 4, 1, 2]
q = [6, 5, 3, 4, 2, 1]
q = [6, 5, 4, 1, 2, 3]
q = [6, 5, 4, 2, 1, 3]
q = [6, 5, 4, 2, 3, 1]
q = [6, 5, 4, 3, 1, 2]
q = [6, 5, 4, 3, 2, 1]
q = [1, 2, 3, 4, 5, 6]
```



```java
class Solution {
    public void nextPermutation(int[] q) {
        int n = q.length;
        
        // System.out.println("n=="+n);
        
        // 从后往前找第一个逆序对
        // [5, 2, 4, 3, 1] 的下一个排列
        int start = -1;
        for(int i = n-2; i >= 0 ; i--){
            if(q[i] < q[i+1]){
                start = i;
                // System.out.println("start=="+start);
                break;
            }
        }
        
        if(start == -1) {
            reverse(q, 0, n-1);
            return;
        }
        
        // 从后往前找到第一个比q[start]大的数
        // 从[5, 2, 4, 3, 1]
        //          j<-j<-j
        int end = 0;
        for(int j = n-1; j > start; j--){
            if(q[j] > q[start]){
                end = j;
                break;
            }
        }
        
        // 交换两个元素的位置 
        // [5, 3, 4, 2, 1]
        swap(q, start, end);
        
        // 翻转后面的元素
        // [5, 3, 1, 2, 4]
        reverse(q, start+1, n-1);
        
        return;
    }
    
    public void swap(int[] q, int start, int end){
        q[start] = q[start] + q[end];
        q[end] = q[start] - q[end];
        q[start] = q[start] - q[end];
    }
    
    public void reverse(int[] q, int start, int end){
        while(start < end){
            swap(q, start, end);
            start++;
            end--;
        }
    }
    
}
```