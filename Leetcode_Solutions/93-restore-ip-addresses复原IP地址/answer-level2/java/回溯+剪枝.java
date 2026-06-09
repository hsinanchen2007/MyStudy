### 解题思路


### 代码

```java
class Solution {
    private List<String> ips = new ArrayList<>();
    public List<String> restoreIpAddresses(String s){
        List<String> segments = new ArrayList<>();
        backtrack(s,0,segments,new StringBuilder());
        return ips;
    }
    private void backtrack(String s,int pos,List<String> segments,StringBuilder sb) {
          int c=segments.size();//因为ip地址有四段,c代表当前解析的有效段数
          int remain=s.length()-pos;//剩余未解析字符长度
          if((4-c)*3<remain){//因为ip地址每段最长是三,剩余的段的最大长度是（4-c）*3,如果小于剩余未解析的长度,说明前面解析错误,在此剪枝
            return;
          }
          if(c==4&&remain==0){//如果c=4，且剩余的字符为0,说明解析成功
              sb.append(segments.get(0));
              for (int i=1;i<c;i++){
                  sb.append('.').append(segments.get(i));
              }
              ips.add(sb.toString());
              sb.delete(0, sb.length());
              return;
          }
          for(int i=pos;i<pos+3&&i<s.length();i++){
              String segment = s.substring(pos, i + 1);
              Integer ipVal = Integer.parseInt(segment);
              String value = String.valueOf(ipVal);
              if(ipVal>255||!value.equals(segment)) break;
              segments.add(segment);
              backtrack(s,i+1,segments,sb);
              segments.remove(segments.size() - 1);
          }
    } 
}
```