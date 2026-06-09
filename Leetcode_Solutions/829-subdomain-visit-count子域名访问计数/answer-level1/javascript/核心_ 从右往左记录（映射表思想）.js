## 解题方案
- 映射表
    - 可用工具类比较轻松，无需考虑数据结构的设计。
    - 使用数组模拟映射表过程稍显复杂，但不难。

### 方法：映射表
#### 思路
在 $Java$ 中借助 $HashMap$，在 `map` 中 `key` 记录域名，对应的 `value` 记录被访问次数。
- 在 $C++，JavaScript$ 等等的高级语言中，我记得同样有映射表这种数据结构。

#### 算法
- 遍历题目给定的域名字符串数组 `cpdomains[]（childred parent domains)`
- 获取当前遍历的域名的原始出现次数，记录于 `num`中。算法为：
    - `count = count * 10 + domain.charAt(pCount++) - '0';`
- 获取当前遍历域名的末尾下标，记录于 `pDomain` 中，`pDomain` 在移动时，遇到 `.` 则暂时停止移动，代表找到一个子域名。
    - `domain.length() - pDomain`即为子域名的域名长度。
- 将该子域名添加进`map`中，并**更新**初始访问次数`count + last_count`，更新完毕后，必须向左移动一步 `pDomain`，因为初始访问次数和域名首字母存在一个空格的间距，这样做可防止造成死循环。
- 重复上述过程置遍历完数组`cpdomains`即可。最后，将`map`中的数据导入`list`中返回。

```Java []
public List<String> subdomainVisits(String[] cpdomains) {

    HashMap<String, Integer> map = new HashMap<>();

    for (String domain : cpdomains) {
        int pCount = 0, count= 0;
        // 计算每个域名前的数字大小
        while (domain.charAt(pCount) != ' ') {
            count= count * 10 + domain.charAt(pCount++) - '0';
        }
        int pDomain = domain.length() - 1;
        // 将以点.分割的各个child_domain和相应访问次数count更新进map
        while (pDomain > pCount) {
            while (domain.charAt(pDomain) != '.' && pDomain > pCount) {
                pDomain -= 1;
            }
            String child_domain = domain.substring(pDomain + 1, domain.length());
            int last_count= map.getOrDefault(child_domain, 0); // 找得到则返回原访问次数，找不到暂时返回0
            map.put(child_domain, last_count + count);  // 更新访问次数
            pDomain -= 1;   //因为再要向左移动1步才能跨过句号(.)
        }
    }
    // 将map中的数据导出，并格式化一下即可
    LinkedList<String> resList = new LinkedList<>();
    for (String child_domain : map.keySet()) {
        resList.addLast(map.get(child_domain) + " " + child_domain);
    }
    return resList;
}
```
### 复杂度分析
- 时间复杂度：$O(len)$，$len$ 是字符串数组 $cpdomains$ 的长度。
- 空间复杂度：$O(len)$，主要占据空间的是映射表。


---
感兴趣的伙伴可提供一下 **其他语言或者说任何语言** 的的实现代码。如果可以将引入并作为文中的一部分，加以标注作者。