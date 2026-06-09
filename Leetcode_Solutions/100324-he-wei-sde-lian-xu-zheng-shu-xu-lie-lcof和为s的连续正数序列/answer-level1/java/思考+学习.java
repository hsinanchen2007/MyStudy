### 解题思路
首先是“连续”,然后就是“整数”，抓住这两点，就能理解到为什么大家都在说双指针和数列等的知识点了。
### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
    /*很重要的一点，题目中的“连续整数序列”。连续--可以用两个指针表示这个连续的范围。还可以使用数列的知识，正数--求方程的根的时候可以根据根为正来缩小范围，方便解题。*/
     int i=1,j=2,sum=i+j;
        if(target<3){
            return null;
        }
        LinkedList<int []> list=new LinkedList<>();
        while (i<j && j<target){
            if(sum<target){
                j++;
                sum+=j;
            }
            else if(sum>target){
                sum-=i;
                i++;
            }
            else{
                int temp[]=new int[j-i+1];
                int x=i;
                for(int m=0;m<temp.length;m++){
                    temp[m]=x++;
                }
                list.add(temp);
                sum-=i;
                i++;
            }
        }
        return list.toArray(new int[0][]);
    }
}
```