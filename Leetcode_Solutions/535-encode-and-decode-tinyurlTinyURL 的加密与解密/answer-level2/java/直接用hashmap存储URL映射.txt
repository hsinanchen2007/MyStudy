最近提交结果：
通过
显示详情 
执行用时 :
11 ms
, 在所有Java提交中击败了
20.30%
的用户
内存消耗 :
36.7 MB
, 在所有Java提交中击败了
68.83%
的用户
```
public class Codec {

    Map<String,String> map = new HashMap<String,String>();
    int max = 'Z';
    Random r=new Random(max);
    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
       int i = 0;
       String key = "";
       while(i<5){
           key+=(char)(r.nextInt(max));
           i++;
       }
       while(map.get(key)!=null){
           key+=r.nextInt();
       }
        map.put(key,longUrl);
        //System.out.println(key);
        return "http://"+key;
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
       // System.out.println(shortUrl);
        
        return map.get(shortUrl.substring(7));
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
```