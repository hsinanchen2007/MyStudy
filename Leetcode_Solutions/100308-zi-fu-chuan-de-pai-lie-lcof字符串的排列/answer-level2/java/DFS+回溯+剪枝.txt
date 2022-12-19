这一题其实就是47题 全排列II的类型
这里我先把代码贴上来
```
public static  String[] permutation(String s) {
        if(s==null || s.length()<1)return new String[]{};
        char[] chars=s.toCharArray();
        Arrays.sort(chars);
        int len=chars.length;
        boolean[] visited=new boolean[len];
        StringBuilder stringBuilder=new StringBuilder();
        List<String> strings=new ArrayList<>();
        dfsString(chars,0,len,visited,stringBuilder,strings);

        String[] res = new String[strings.size()];
        int i=0;
        for(String si:strings){
            res[i++]=si;
        }
        return res;
    }

    private static void dfsString(char[] chars, int pos, int len, boolean[] visited, StringBuilder temp, List<String> strings) {
        if(pos==len){
            strings.add(temp.toString());
        }
        for(int i=0;i<len;i++){
            if (visited[i]) {
                continue;
            }
            if(i>0 && chars[i]==chars[i-1] && !visited[i-1]){
                continue;
            }

            temp.append(chars[i]);
            visited[i]=true;
            dfsString(chars,pos+1,len,visited,temp,strings);
            temp.deleteCharAt(temp.length()-1);
            visited[i]=false;
        }
    }
```
这道题有两个地方需要注意：
第一：就是怎样判断重复，这里我直接利用Arrays.sort(),直接排序，然后在深度搜索的时候，利用前后两个字符是否一样来进行剪枝
if(i>0 && chars[i]==chars[i-1] && !visited[i-1])
i>0 是为了保证取得到 !visited[i-1] 而这一步是判断前一个字符有没有被选择过

接下来这几步。应该就是常规操作啦
temp.append(chars[i]);
visited[i]=true;
dfsString(chars,pos+1,len,visited,temp,strings);
temp.deleteCharAt(temp.length()-1);
visited[i]=false;

新手题解 互相学习