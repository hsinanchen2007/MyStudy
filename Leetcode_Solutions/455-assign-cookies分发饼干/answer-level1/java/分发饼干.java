### 解题思路
对胃口和饼干大小进行排序，之后使用双重循环按照孩子胃口进行匹配饼干，如果第一个孩子匹配成功，下一个孩子从他匹配的饼干下一个开始，不从头开始。
设置一个计数变量count匹配成功时加1，最后返回count

### 代码

```java
class Solution {
 public int findContentChildren(int[] g, int[] s) {
        //对胃口和尺寸从小到大排序
        Arrays.sort(g);
        Arrays.sort(s);
        int n=0;
        int count=0;
        for(int i=0;i<g.length;i++){
             for(int j=n;j<s.length;j++){
                 if(g[i]<=s[j]){
                     count++;
                     n=j+1;
                     break;
                 }
             }
        }
        return count;
    }
}
```