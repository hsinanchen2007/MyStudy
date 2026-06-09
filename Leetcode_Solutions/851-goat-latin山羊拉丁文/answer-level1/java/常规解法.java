### 解题思路
拆分字符串后得到单词数组，一个一个的处理

### 代码

```java
class Solution {
    private List<Character> y=new ArrayList();
    private StringBuilder ans=new StringBuilder();
    public String toGoatLatin(String S) {
        y.add('a');
        y.add('e');
        y.add('i');
        y.add('o');
        y.add('u');
        y.add('A');
        y.add('E');
        y.add('I');
        y.add('O');
        y.add('U');
        String[] items=S.split(" ");
        int i=0;
        for(String item:items){
            buildStrItem(item,i);
            i++;
        }
        return ans.toString();
    }

    private void buildStrItem(String item,int index){
        if(item==null||item==""){
            return;
        }
        if(index>0){
            ans.append(" ");
        }
        if(y.indexOf(item.charAt(0))>-1){
            ans.append(item).append("ma");
            while(index>=0){
                ans.append("a");
                index--;
            }
        }else{
            ans.append(item.substring(1)).append(item.charAt(0)).append("ma");
            while(index>=0){
                ans.append("a");
                index--;
            }
        }
    }
}
```