虽然写完后看了一下官方题解，感觉好简单，但是为什么官方题解那么费时？萌新小白跪求大佬解惑。。。
下面是我自己写的代码。
```
class Solution {
    public int firstUniqChar(String s) {
       char[] ch=s.toCharArray();
        Map<Object,Integer> same=new HashMap();  
        for(int i=0;i<ch.length;i++){
            boolean unique=true;
            if(same.containsKey(ch[i])){continue;}
            for(int j=i+1;j<ch.length;j++){
                if(ch[i]==ch[j]){
                    same.put(ch[i],1);
                    unique=false;
                    break;
                }
            }
            if(unique){return i;}
        }
        return -1;
    }
}
```

