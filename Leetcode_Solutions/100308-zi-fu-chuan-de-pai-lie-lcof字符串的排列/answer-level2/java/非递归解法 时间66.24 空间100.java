### 解题思路
基本思路：插缝法
例如：s="abcd"
"a"仅存在一种顺序，第二个字符b进来后，可以插到a前面，也可以插到a后面，从而出现了“ab”  “ba”两种形式；
第三个字符“c”，便分别插入“ab“ ”ba“的缝隙中出现 cab,acb,abc , cba,bca,bac
以此类推，即可得到全部解。另外为了避免重复，每个步骤加入HashSet操作来进行判重。


### 代码

```java
class Solution {
    public String[] permutation(String s) {
        //边界值处理
        if(s==null){
            return new String[0];
        }
        if(s.length()==0){
            return new String[]{""};
        }
        //用于判重
        HashSet<String> sets=new HashSet<>();
        //用于遍历，保存最终结果（类似于BFS的写法）
        Queue<String>queue=new LinkedList<>();
        queue.add(s.substring(0,1));
        while(!queue.isEmpty()){
            int length=queue.peek().length();
            if(length==s.length()){
                //queue中字符长度等于s的长度，则表示已组合完毕，直接退出while循环
                break;
            }
            int size=queue.size();
            while(size-->0){
                String tmpStr= queue.poll();
                for(int i=0;i<=tmpStr.length();i++){
                    StringBuilder sBuilder=new StringBuilder();
                    //将下一个字符插入位置i
                    sBuilder.append(tmpStr.substring(0,i)).append(s.charAt(length)).append(tmpStr.substring(i,length));
                    String tmpRes=sBuilder.toString();
                    //HashSet判重
                    if(sets.add(tmpRes)){
                        queue.add(tmpRes);
                    }
                }
            }
        }
        String[]res=new String[queue.size()];
        int count=0;
        //从queue转为String数组
        while(!queue.isEmpty()){
            res[count++]=queue.poll();
        }
        return res;
    }
}
```