这道题应该分为两种情况来考虑
第一种：
![image.png](https://pic.leetcode-cn.com/042062084998b0fdda34a0a064a42ecad28d403120be4c6e77ff918f52732702-image.png)
**此时s1中的字符串与s2是一一对应的**
第二种：
![image.png](https://pic.leetcode-cn.com/04035f4dd4a3087845b453dcfddb2b9d866aa00476f67f7c4c1e63a6f72e2183-image.png)
**此时s1中的前半段对应s2的后半段，s1的后半段对应s2的前半段**
所以在这里我们只需要遍历s1的所有的切割点，判断这两种情况中的一种满足就可以返回true，当然这里要加一个记忆化，因为对s1和s2的子字符串会有重复的计算，将它们保存到一个map中，遇到重复的情况直接返回对应的结果，省去了一部分的计算
<br>
```java
class Solution {
   private Map<String,Boolean> map=new HashMap<String,Boolean>();
	
	public boolean isScramble(String s1, String s2) {
        int n=s1.length(); int m=s2.length();
        //如果两个字符串的长度不同，那s2绝对不是s1的扰乱字符串
        if(n!=m) return false;
        
        if(map.containsKey(s1+"#"+s2)) return map.get(s1+"#"+s2);
        
        if(s1.equals(s2)) return true;//如果两个字符串完全相同，那s2也是s1的扰乱字符串
        
        //如果s2中含有s1中没有的字符，那s2也绝不是s1的扰乱字符串
        int[] cnt=new int[26];
        for(int i=0;i<n;i++) {
        	cnt[s1.charAt(i)-'a']++;
        	cnt[s2.charAt(i)-'a']--;
        }
        for(int i=0;i<26;i++) if(cnt[i]!=0) return false; 
        
        //遍历s1的所有的切割点
        for(int i=1;i<n;i++){
            if(isScramble(s1.substring(0,i),s2.substring(0,i))){
            	map.put(s1.substring(0,i)+"#"+s2.substring(0,i), true);
            	if(isScramble(s1.substring(i),s2.substring(i))){
            		return true;
            	}
                map.put(s1.substring(i)+"#"+s2.substring(i), false);
            }
            	
            if(isScramble(s1.substring(0,i),s2.substring(n-i))) {
            	map.put(s1.substring(0,i)+"#"+s2.substring(n-i), true);
            	if(isScramble(s1.substring(i),s2.substring(0,n-i))){
            		return true;
            	}
                map.put(s1.substring(i)+"#"+s2.substring(0,n-i),false);
            }
        }
        
        return false;
    }
}
```