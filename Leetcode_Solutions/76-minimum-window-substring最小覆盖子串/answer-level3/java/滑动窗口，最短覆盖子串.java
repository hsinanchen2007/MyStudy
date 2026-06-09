### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String minWindow(String s, String t) {
        if(s.length()==0){
            return "";
        }
        Map<Character,Integer> map=new HashMap<>();
        for(char c:s.toCharArray()){
            map.put(c,0);
        }
        for(char c:t.toCharArray()){
            if(map.containsKey(c)){
                map.put(c,map.get(c)+1);
            }else{
                return "";
            }
        }
        
        String result="";
        int left=0;
        int right=0;
        int count=t.length();
        
        while(right<s.length()){// 先移动 right 寻找可行解
            char c=s.charAt(right);
            if(map.get(c)>0){
                count--;
            }
            map.put(c,map.get(c)-1);
            right++;
            while(count==0){
                if(result==""){// 如果这个窗口的子串更短，则更新结果
                    result=s.substring(left,right);
                }else if(result.length()>(right-left)){
                    result=s.substring(left,right);
                }
                
                char c1=s.charAt(left);// 找到可行解后，开始移动 left 缩小窗口
                if(map.get(c1)==0){
                    count++;
                }
                map.put(c1,map.get(c1)+1);
                left++;
            }
        }
        return result;
    }
}
```