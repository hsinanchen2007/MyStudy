### 解题思路
* 性能对比纯API方案
* 其他方案参考其他童鞋的作品改写

### 代码
// 方案一、纯Java API实现，击败5.09%的用户
```java []
class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<String> data = new ArrayList<>();
        for(int i = 1; i <= n; i++) {
                data.add(Integer.toString(i));
        }
       data.sort(String::compareTo);
       return data.stream().mapToInt(Integer::parseInt).boxed().collect(Collectors.toList());
    }
}
```
```java []
// 方案二、参考C++评论方案，击败52.01%的用户
class Solution {
    public List<Integer> lexicalOrder(int n) {
       List<Integer> data = new ArrayList<>();
       int cur=1;
        for(int i=0;i<n;i++){
            data.add(cur);
            if(cur*10<=n){
                cur*=10;
            }else{
                if(cur>=n) cur/=10;
                cur+=1;
                while(cur%10==0) cur/=10;
            }
        }
        return data;
    }
}
```