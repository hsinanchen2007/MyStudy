### 解题思路

每一条cpdomain的构成是一个数字接一个字符串，中间用空格隔开
使用`String#split`省略参数，即将中间的空格作为分割符得到2个参数n与w

n为数字字符串，调用`to_i`转为整数
用数组f存储w所包含的所有子域名，首先包含完整域名w
随后使用`String#match`不断对w进行匹配
规则`/.+?\./`代表先匹配1个以上的任意字符且尽量短，之后匹配一个`.`
匹配的结果存在md中，如果匹配失败则循环结束
匹配成功则用匹配剩余的部分替换w，并将其存入数组f

以"discuss.leetcode.com"为例，在f初始化时就包含了"discuss.leetcode.com"
随后其匹配`/.+?\./`的部分为"discuss."，剩余部分为"leetcode.com"
这时将剩余部分存入f，再次匹配，剩余部分为"com"，不满足正则，循环结束。
循环结束后后，f为["discuss.leetcode.com", "leetcode.com", "com"]，符合需要。

为了保证重复出现的域名被累加计数，使用带默认值0的哈希`Hash.new(0)`来存储域名的访问次数。
迭代数组f，用域名作为键，直接将值累加n。

所有域名计数完毕后，用`Enumerable#map`将哈希的键与值拼成字符串`"#{k} #{v}"`，
得到题目需要的数组。



### 代码

```ruby
def subdomain_visits(cpdomains)
	i = 0
	m = cpdomains.size
	h = Hash.new(0)
	while i < m
		n, w = cpdomains[i].split
		n = n.to_i
		f = [w]
		while md = w.match(/.+?\./)
			w = md.post_match
			f << w
		end
		o = f.size
		j = 0
		while j < o
			h[f[j]] += n
			j += 1
		end
		i += 1
	end
    h.map{|k, v|  "#{v} #{k}" }
end
```

执行用时 :76 ms, 在所有 Ruby 提交中击败了100.00%的用户
内存消耗 :10.1 MB, 在所有 Ruby 提交中击败了100.00%的用户