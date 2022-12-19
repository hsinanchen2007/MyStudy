### 提交结果
![image.png](https://pic.leetcode-cn.com/680b115fed4b9924469a8d5e243fcfbee560a7bfa103a0061f8a3212cb224b1a-image.png)
尽管不用正则也可以，但最近在死磕正则，所以第一时间还是想到正则

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
		return s.replaceAll("\\s", "%20");
        
    }
}
```