### 解题思路
希望下面的图片能帮助理解，代码中也有注释
![image.png](https://pic.leetcode-cn.com/7d69c10e4d2c0b938724ab1805f889d20802585ebb9d1fba1c746f8508554df1-image.png)
时间复杂度：O(n)
空间复杂度：O(1)
### 代码

```java
class Solution {
    public int hIndex(int[] citations) {
        int hIndex=0,N=citations.length;
        //先对论文引用数排序
        Arrays.sort(citations);
        for(int i=N-1;i>=0;i--){
            int h=N-i;//至多有h篇论文
            if(citations[i]>=h//至多h篇论文至少被引用h次
                &&(i==0?0:citations[i-1])<=h)//其余N-h篇论文至多被引用h次
                //若该h指数更大，则保存
                hIndex=hIndex>h?hIndex:h;
        }
        return hIndex;
    }
}
```