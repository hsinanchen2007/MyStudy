异或问题排查是否存在只出现一次的数字
通过异或位操作来解决正常出现2次，排查只出现一次的数字，这种场景，我记得在Storm实时计算引擎中，在各sink之间为了监控消息是否正确处理，storm后台有一种机制对每条消息Id在生产端和消费端都会写入后台，然后在后台对消息Id进行异或，即可检查那条数据没有被正确处理，然后让生产端重新发送。
```java
class Solution {
    public int singleNumber(int[] nums) {
        int res = 0;
        for(int num : nums){
            res = res ^ num;
        }
        return res;
    }
}
```
