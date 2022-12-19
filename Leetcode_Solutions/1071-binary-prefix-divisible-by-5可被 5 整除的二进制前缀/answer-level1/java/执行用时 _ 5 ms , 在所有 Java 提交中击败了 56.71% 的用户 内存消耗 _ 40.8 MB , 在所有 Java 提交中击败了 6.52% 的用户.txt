### 解题思路
这是一道典型的不能使用求和的题目，测试用例给的很刁钻，故意溢出int类型的最大值，逼迫我们不能使用传统的求和取余判断，相对应的，我们要处理这个和，那么什么时候能被5整除？末位为0或5即可，所以只要sum大于0，我们就减去10，然后看该值是否为0或5，是的话，为真，不是，为假，依次循环遍历完成后，我们返回该List集合即可，代码如下。

### 代码

```java
class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean> list = new ArrayList<Boolean>();
        int sum = 0;
        for(int i = 0;i<A.length;i++) {
            sum+=A[i];
            sum = sum>9?sum-10:sum;
            if(sum==0||sum==5) {
                list.add(true);
            }else list.add(false);
            sum = sum*2;
        }
        return list;
    }
}
```