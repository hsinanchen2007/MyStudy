### 解题思路
此处撰写解题思路

### 代码

```java
public class Codec {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        if(strs==null||strs.size()==0)
            return null;
        StringBuilder header=new StringBuilder();
        StringBuilder body=new StringBuilder();
        for(int i=0;i<strs.size();i++)
        {
            header.append(strs.get(i).length());
            if(i!=strs.size()-1)
                header.append(",");
            body.append(strs.get(i));
        }

        StringBuilder sb=new StringBuilder();
        sb.append(header);
        sb.append(" ");
        sb.append(body);
        return sb.toString();
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        List<String> res=new ArrayList<>();
        if(s==null||s.length()==0)
            return res;
        int i=0;
        while (s.charAt(i)!=' ')
            i++;
        String lens=s.substring(0,i);
        String [] lenArr=lens.split(",");
        i++;
        for(String len:lenArr){
            Integer l=Integer.valueOf(len);
            String str=i<s.length()? s.substring(i,i+l):"";
            i+=l;
            res.add(str);
        }
        return res;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));
```