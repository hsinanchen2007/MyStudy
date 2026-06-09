### 解题思路
1.将@前后字符分割开
2.判断本地名是否有"."和"+",做对应处理
3.判断是否重复加入集合

### 代码

```java
class Solution {
    public int numUniqueEmails(String[] emails) {
            List<String> adress=new ArrayList<>();
		for(int i=0;i<emails.length;i++) {
			//获取本地名
			String str=emails[i].substring(0, emails[i].indexOf("@"));
			//获取本域名
			String str1=emails[i].substring(emails[i].indexOf("@"));
		
			//判断是否包含'.',包含去掉
			if (str.indexOf(".")!=-1) {
				str=str.replace(".", "");
			}
			//判断是否有＋,有的话,截取＋之前的字符
			if (str.indexOf("+")!=-1) {
				str=str.substring(0, str.indexOf("+"));
			}
			//拼接成完整邮件地址
			String finaladdress=str+str1;
			//判断集合是否有当前邮箱地址,,没有添加到集合中
			if (!adress.contains(finaladdress)) {
				adress.add(finaladdress);
			}
			
		}
        return adress.size();
    }
}
```