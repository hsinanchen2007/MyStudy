### 解题思路
利用快速排序的思想,用于判断前k个最小数,但是没说必须保证顺序,所以使用快排,只要取到
注意找前K大/前K小问题不需要对整个数组进行O(NlogN)的排序！
本题，直接通过快排切分排好第K小的数（下标为K-1），那么它左边的数就是比它小的另外K-1个
### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        //快速排序
        quickSort(arr,0,arr.length-1,k);
        int []result=new int[k];
        for(int i=0;i<k;i++){
            result[i]=arr[i];
        }
        return result;
    }
    private void quickSort(int[] arr,int l,int r, int k){
        if(l<r){
            //取第一个元素作为标记进行比较,大于flag的放到右边,小于flag放到左边
            int flag=arr[l];
            int i=l,j=r;
            //左边的下标小于右边下标,当相等时重叠不在交换
            while(i<j){
                //一直循环,直到找到右边的元素小于flag
                while(i<j&&arr[j]>flag){
                    j--;
                }
                if(i<j){
                    //互换元素,将小元素换到左边
                    arr[i]=arr[j];
                    i++;
                }
                //一直循环,直到找到左边的元素大于flag
                while(i<j&&arr[i]<flag){
                    i++;
                }
                if(i<j){
                    //互换元素,将大元素换到右边
                    arr[j]=arr[i];
                    j--;
                }
            }
            //交换结束,将标记为放到i的位置,此时i=j,arr[i-1]都小于a[i],arr[i+1]都大于a[i]
            arr[i]=flag;
            //注意,如果是快排没有该判断.前k个数,下标是k-1,所以如果i=k-1说明前面k个数是最小的直接结束排序即可
            if(i!=k-1){
                quickSort(arr,l,i-1,k);
                quickSort(arr,i+1,r,k);
            }

        }
    }


}
```