### 解题思路
窗口法，挺好玩的

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        int i=1;
        int j=1;
        int sum=0;
        ArrayList<int[]> list = new ArrayList<>();
        while(i<=target/2){
            if(sum<target){
                //移动右侧边界
                sum+=j;
                j++;
            }else if(sum>target){
                //移动左侧边界
                sum-=i;
                i++;
            }else{
                //相等时调整
                int[] a=new int[j-i];
                for(int k=i;k<j;k++){
                    a[k-i]=k;
                }
                list.add(a);
                //移动右侧边界
                sum+=j;
                j++;
            }
        }
        return list.toArray(new int[list.size()][]);
    }
}
```

我是一只小菜鸡，小呀小菜鸡