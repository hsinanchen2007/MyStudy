### 解题思路
白板bugfree挑战，没有考虑到最后的#需要排除掉，还是用ide debug出来的，悲伤。

### 代码

```java
public class Codec {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();
        int count =0;
        for (String str:strs){
            count++;
            sb.append(str);
            sb2.append("-"+String.valueOf(str.length()));
        }
        return sb.toString()+sb2.toString()+"#"+String.valueOf(count);
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        int index = s.lastIndexOf("#");
        int count = Integer.parseInt(s.substring(index+1));
        int[] strLens = new int[count];
        String[] strs = s.substring(0, index).split("-");
        for (int i=0; i<count; i++){
            strLens[i] = Integer.parseInt(strs[strs.length-count+i]);
        }
        List<String> list = new LinkedList<>();
        int cmp = 0;
        for (int len : strLens){
            list.add(s.substring(cmp, cmp+len));
            cmp += len;
        }
        return list;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));
```