```
public String minWindow(String s, String t) {
        //先循环窗口向右扩大来进行匹配，若匹配成功循环进行窗口左边界向左缩小
        Map<Character, Integer> map = new HashMap<>();
        for (char c : t.toCharArray()) {//记录t中字符的数量到map中
            Integer i= map.get(c);
            if(i!=null){
                map.put(c, i + 1);
            }else {
                map.put(c,1);
            }
        }
        String result = "";
        //记录剩余需要被匹配的个数
        int count = t.length();
        int right = 0;
        int left = 0;
        while (right < s.length()) {
            char c = s.charAt(right);
            Integer value=map.get(c);
            if (value!=null){//发现匹配字符
                if(value>0)
                    count--;
                map.put(c, value - 1);
            }
            right++;
            while (count == 0) {//如果此窗口已经匹配成功
                //若当前短于answer则替换answer
                if(result.length() == 0){
                    result = s.substring(left, right);
                }else if (result.length() > (right - left)) {
                    result = s.substring(left, right);
                }
                //移动左指针，缩小窗口存下最小的窗口，当缩小到不匹配t为止
                char c1 = s.charAt(left);
                Integer i=map.get(c1);
                if (i!=null) {//若t中存在此字符
                    if(i == 0)
                        count++;//若此字符删除后此字符待匹配次数大于0(也就是说窗口此时不匹配t了)则结束窗口缩小循环
                    map.put(c1,i + 1);//窗口缩小而删除了此字符，因此此字符待匹配次数+1
                }
                left++;
            }
        }
        return result;
    }
```
