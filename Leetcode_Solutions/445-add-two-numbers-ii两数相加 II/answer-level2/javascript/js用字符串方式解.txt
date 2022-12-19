### 1.字符串简单思路（运行会出错）
```

var addTwoNumbers = function (l1, l2) {
  let str1 = '', str2 = '', ret = proxy = new ListNode(0)
  while (l1) {
    str1 += l1.val
    l1 = l1.next
  }
  while (l2) {
    str2 += l2.val
    l2 = l2.next
  }

  let sr = str1 - 0 + (str2 - 0) + ''
  console.log(sr, str1, str2)
  Array.prototype.forEach.call(sr, v => {
    proxy.next = new ListNode(v)
    proxy = proxy.next
  })

  return ret.next
};
```

*很容易理解， 但是科学计数法会导致问题
******
### 2.字符串 自顶向下（skyline）
```
var addTwoNumbers = function (l1, l2) {
  let m = 0, n = 0, str1 = '', str2 = '', ret = proxy = new ListNode(0)
  while (l1) {
    m++
    str1 += l1.val
    l1 = l1.next
  }
  while (l2) {
    n++
    str2 += l2.val
    l2 = l2.next
  }
  if (m > n) {
    str2 = '0'.repeat(m - n) + str2
  }

  if (m < n) {
    str1 = '0'.repeat(n - m) + str1
  }

	// 求和
  let l = str1.length, up = false, strRet = ''
  while(l--) {
    strRet = (Number(str1[l]) + Number(str2[l]) + up) % 10 + strRet
    up = Number(str1[l]) + Number(str2[l]) + up > 9
  }
  up && (strRet = '1' + strRet)
	
  Array.prototype.forEach.call(strRet, v => {
    proxy.next = new ListNode(v)
    proxy = proxy.next
  })

  return ret.next
};
```

* 在1的基础上解决求和产生的科学计数法的问题
* 循环时由最高位向最低位，利用proxy不断向低位移动

