首先再maxCost 大于全部距离和的情况下，可以直接返回字符串长度

快慢指针维护一个距离窗口，每次添加距离前检查距离是否超过maxCost
```
class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int len = s.length();
        
        int[] dis = new int[len];
        char[] sa = s.toCharArray();
        char[] ta = t.toCharArray();
        int sum = 0;
        for(int i = 0; i < len; ++ i) {
            int d = sa[i] - ta[i];
            dis[i] = Math.abs(d);
            sum += dis[i];
        }
        if(sum <= maxCost) {
            return len;
        }
        int ret = 0;
    
        int slow = 0;
        int fast = 0;
        int cost = 0;
        
       
        while(fast < len && slow < len) {
            
            if(cost + dis[fast] < maxCost) {
                cost += dis[fast];
                fast ++;
            } else if(cost + dis[fast] == maxCost) {
                cost += dis[fast];
                ret = Math.max(ret, fast - slow + 1);
                
                fast ++;
            } else if(cost + dis[fast] > maxCost) {
                ret = Math.max(fast - slow, ret);
                cost -= dis[slow];
                slow ++;
            }
            
        }
        
        if(fast == len) {
            ret = Math.max(ret, fast - slow);
        }
        
        return ret;
        
        // return ret;
    }
}
```
