### 解题思路
此处撰写解题思路

### 代码

```java
public class Codec {

    // Encodes a URL to a shortened URL.
    private static int key=10;
    public String encode(String longUrl) {
        char [] c=longUrl.toCharArray();
        for(int i=0;i<c.length;i++)
        {
            c[i]^=key;
        }
        String encode=new String(c);
        return "http://"+encode;
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        char [] c=shortUrl.substring(7).toCharArray();
        for(int i=0;i<c.length;i++)
            c[i]^=key;
        return new String(c);
        
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
```