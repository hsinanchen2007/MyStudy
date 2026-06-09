#### 概述

最直接的方法是使用内置函数和 try/catch 结构检查 IP 地址的正确性：在 Python 中使用 [ipaddress](https://docs.python.org/3/library/ipaddress.html) ，在 Java 中使用 [InetAddress](https://docs.oracle.com/javase/7/docs/api/java/net/InetAddress.html) 。

```python [solution1-Python]
from ipaddress import ip_address, IPv6Address
class Solution:
    def validIPAddress(self, IP: str) -> str:
        try:
            return "IPv6" if type(ip_address(IP)) is IPv6Address else "IPv4"
        except ValueError:
            return "Neither"
```

```java [solution1-Java]
import java.net.*;
class Solution {
  public String validIPAddress(String IP) {
    try {
      return (InetAddress.getByName(IP) instanceof Inet6Address) ? "IPv6": "IPv4";
    } catch(Exception e) {}
    return "Neither";
  }
}
```

注意：这两个类都是引用 [POSIX -兼容的](https://linux.die.net/man/3/inet_addr) `inet-addr()` 解析地址。如果地址带有前导零块，可能会发生错误。

> 地址的组成可以使十进制，八进制（以 0 开始），或十六进制（以 0X 开始）。

例如 `01.01.01.012` 是有效的八进制 IP 地址。检查该地址是否有效可以在控制台运行命令 `ping 01.01.01.012`，八进制地址 `01.01.01.012` 会被转换为对应的十进制地址 `1.1.1.10`，因此执行 ping 命令不会出错。

该题目指出如果 *IPv4 地址包含前置 0，则地址是无效的* ，但其实这不符合真实情况，不过我们仍然需要解决它。

该题目要三种主要解法：

- 正则表达式，该方法性能不太好。

- 分治法，效率最高的方法之一。

- 使用分治法和内置的 try/catch，将字符串转换成整数处理。使用 try/catch 不是一种好的方式，因为 try 块中的代码不会被编译器优化，所以最好不要在面试中使用。


#### 方法一：正则表达式

构造适用该题目的 “IPv4” 地址的正则表达式。注意前面讨论的前置零问题，它不属于 IPv4 地址。

在 Python 中使用原始字符串 `r''` 构造正则表达式：

![](https://pic.leetcode-cn.com/Figures/468/regex_ipv4.png)

在 Java 中使用标准字符串构造正则表达式：

![](https://pic.leetcode-cn.com/Figures/468/java_ipv4.png)

现在问题被简化为检查每个块是否正确，每个块的范围为 `(0, 255)`，且不允许有前置零出现。一共有五种情况：

1. 块只包含一位数字，范围是 0 到 9。

2. 块包含两位数字，第一位的范围是 1 到 9，第二位是 0 到 9。

3. 块包含三位数字，且第一位为 1。第二、三位可以是 0 到 9。

4. 块包含三位数字，且第一位为 2，第二位为 0 到 4。那么第三位可以是 0 到 9。

5. 块包含三位数字，且第一位为 2，第二位为 5，那么第三位可以是 0 到 5。

创建包含这 5 种情况的正则表达式。

![](https://pic.leetcode-cn.com/Figures/468/chunk_regex.png) 

使用相同逻辑构造匹配 IPv6 地址的正则表达式。

```python [solution1-Python]
import re
class Solution:
    chunk_IPv4 = r'([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])'
    patten_IPv4 = re.compile(r'^(' + chunk_IPv4 + r'\.){3}' + chunk_IPv4 + r'$')
    
    chunk_IPv6 = r'([0-9a-fA-F]{1,4})'
    patten_IPv6 = re.compile(r'^(' + chunk_IPv6 + r'\:){7}' + chunk_IPv6 + r'$')

    def validIPAddress(self, IP: str) -> str:        
        if '.' in IP:
            return "IPv4" if self.patten_IPv4.match(IP) else "Neither" 
        if ':' in IP:
            return "IPv6" if self.patten_IPv6.match(IP) else "Neither" 
        return "Neither"
```

```java [solution1-Java]
import java.util.regex.Pattern;
class Solution {
  String chunkIPv4 = "([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])";
  Pattern pattenIPv4 =
          Pattern.compile("^(" + chunkIPv4 + "\\.){3}" + chunkIPv4 + "$");

  String chunkIPv6 = "([0-9a-fA-F]{1,4})";
  Pattern pattenIPv6 =
          Pattern.compile("^(" + chunkIPv6 + "\\:){7}" + chunkIPv6 + "$");

  public String validIPAddress(String IP) {
    if (IP.contains(".")) {
      return (pattenIPv4.matcher(IP).matches()) ? "IPv4" : "Neither";
    }
    else if (IP.contains(":")) {
      return (pattenIPv6.matcher(IP).matches()) ? "IPv6" : "Neither";
    }
    return "Neither";
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(1)$。
    
* 空间复杂度：$\mathcal{O}(1)$。


#### 方法二：分治法

**思想**

IPv4 和 IPv6 地址均是由特定的分界符隔开的字符串组成，并且每个子字符串具有相同格式。

![](https://pic.leetcode-cn.com/Figures/468/divide_conquer.png)

因此，可以将地址分为多个块，然后逐块进行验证。

仅当每个块都有效时，该地址才有效。这种方法称为 *分治法*。

**算法**

- 对于 IPv4 地址，通过界定符 `.` 将地址分为四块；对于 IPv6 地址，通过界定符 `:` 将地址分为八块。

- 对于 IPv4 地址的每一块，检查它们是否在 `0 - 255` 内，且没有前置零。

- 对于 IPv6 地址的每一块，检查其长度是否为 `1 - 4` 位的十六进制数。

```python [solution2-Python]
class Solution:
    def validate_IPv4(self, IP: str) -> str:
        nums = IP.split('.')
        for x in nums:
            # Validate integer in range (0, 255):
            # 1. length of chunk is between 1 and 3
            if len(x) == 0 or len(x) > 3:
                return "Neither"
            # 2. no extra leading zeros
            # 3. only digits are allowed
            # 4. less than 255
            if x[0] == '0' and len(x) != 1 or not x.isdigit() or int(x) > 255:
                return "Neither"
        return "IPv4"
    
    def validate_IPv6(self, IP: str) -> str:
        nums = IP.split(':')
        hexdigits = '0123456789abcdefABCDEF'
        for x in nums:
            # Validate hexadecimal in range (0, 2**16):
            # 1. at least one and not more than 4 hexdigits in one chunk
            # 2. only hexdigits are allowed: 0-9, a-f, A-F
            if len(x) == 0 or len(x) > 4 or not all(c in hexdigits for c in x):
                return "Neither"
        return "IPv6"
        
    def validIPAddress(self, IP: str) -> str:
        if IP.count('.') == 3:
            return self.validate_IPv4(IP)
        elif IP.count(':') == 7:
            return self.validate_IPv6(IP)
        else:
            return "Neither"
```

```java [solution2-Java]
class Solution {
  public String validateIPv4(String IP) {
    String[] nums = IP.split("\\.", -1);
    for (String x : nums) {
      // Validate integer in range (0, 255):
      // 1. length of chunk is between 1 and 3
      if (x.length() == 0 || x.length() > 3) return "Neither";
      // 2. no extra leading zeros
      if (x.charAt(0) == '0' && x.length() != 1) return "Neither";
      // 3. only digits are allowed
      for (char ch : x.toCharArray()) {
        if (! Character.isDigit(ch)) return "Neither";
      }
      // 4. less than 255
      if (Integer.parseInt(x) > 255) return "Neither";
    }
    return "IPv4";
  }

  public String validateIPv6(String IP) {
    String[] nums = IP.split(":", -1);
    String hexdigits = "0123456789abcdefABCDEF";
    for (String x : nums) {
      // Validate hexadecimal in range (0, 2**16):
      // 1. at least one and not more than 4 hexdigits in one chunk
      if (x.length() == 0 || x.length() > 4) return "Neither";
      // 2. only hexdigits are allowed: 0-9, a-f, A-F
      for (Character ch : x.toCharArray()) {
        if (hexdigits.indexOf(ch) == -1) return "Neither";
      }
    }
    return "IPv6";
  }

  public String validIPAddress(String IP) {
    if (IP.chars().filter(ch -> ch == '.').count() == 3) {
      return validateIPv4(IP);
    }
    else if (IP.chars().filter(ch -> ch == ':').count() == 7) {
      return validateIPv6(IP);
    }
    else return "Neither";
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(1)$。
    
* 空间复杂度：$\mathcal{O}(1)$。