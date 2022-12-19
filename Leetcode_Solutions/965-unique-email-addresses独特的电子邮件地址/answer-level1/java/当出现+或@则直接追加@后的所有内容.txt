### 解题思路
由于必定存在 '@' 在出现 '+'或'@'后直接追加 '@'即后续的内容即可
...
...

### 代码

```java
class Solution {
    public int numUniqueEmails(String[] emails) {
        HashSet<String> set = new HashSet<>();
        //StringBuilder sb;
        MyStringBuilder sb = new MyStringBuilder(emails[0].length());
        for(String s : emails){
            //sb = new StringBuilder(s.length());
            char[] ch = s.toCharArray();
            f2 : for(int i=0;i < ch.length;i++){
                s : switch(ch[i]){
                    case '.':
                        break s;
                    case '+':
                        i = s.indexOf('@');//find(ch,i);
                    case '@':
                        sb.append(ch,i,ch.length - i);
                        break f2;
                    default:
                        sb.append(ch[i]);
                }
            }

            // for(char c : s.toCharArray()){
            //     if(c == '.')
            //         continue;
            //     else if(c == '@' || c == '+'){
            //         int index = s.indexOf('@');
            //         sb.append(s,index,s.length());
            //         break;
            //     }else{
            //         sb.append(c);
            //     }
            // }

            set.add(sb.toString());
            sb.clean();
        }
        return set.size();
    }

    public int find(char[] ch,int i){
        for(;i<ch.length;i++){
            if(ch[i] == '@')
                return i;
        }
        return -1;
    }

    class MyStringBuilder{
        private char[] data;
        private int size;
        
        public  MyStringBuilder(int capacity){
            data = new char[capacity];
            size = 0;
        }
        
        public void append(char c){
            if (size >= data.length)
                resize(2*data.length);
            data[size++] =  c;
        }
        public void append(char[] ch,int start,int len){
            if (size+len >= data.length)
                resize(size+len);
            for (int i=0;i < len;i++)
                data[size+i] = ch[start+i];
            size += len;
        }
        public void clean(){
            size = 0;
        }

        @Override
        public String toString() {
            return new String(data,0,size);
        }

        public void resize(int capacity){
            char[] newData = new char[capacity];
            for (int i=0;i < size;i++){
                newData[i] = data[i];
            }
            data = newData;
        }
    }
}
```