![image.png](https://pic.leetcode-cn.com/eccba584ca2cf48273155c579df1fe5f0794b44967d350956f391040c93c2456-image.png)

先按照@分割出本地名称和域名；
再把域名按照“+”分割，取第一个“+”前面的部分；
去除“.”
```
class Solution {
        public int numUniqueEmails(String[] emails) {
            if (emails==null)
                return -1;
            Set<String> set = new HashSet<>();
            for (int i = 0; i <emails.length ; i++) {
                String[] email = emails[i].split("@");
                String local = email[0];
                String domain = email[1];
                String[] effLocal = local.split("\\+")[0].split("\\.");//本地名称中的有效字符
                StringBuilder sb=new StringBuilder();
                for (int j = 0; j <effLocal.length ; j++) {
                    sb.append(effLocal[j]);
                }
                sb.append("@").append(domain);
                set.add(sb.toString());
            }
            return set.size();
        }
    }
```
