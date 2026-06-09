// >天下武功, 无坚不破, 唯快不破 ——— 火云邪神

// 本文为我,`leetcode easy player`,`algorithm(算法)小xuo生`在刷题过程中对快慢指针的应用的总结

// ps: 向`leetcode`里耐心写解题, 特别是画图解题的各位算法大佬们致敬

// # 什么是快慢指针
// 1. `快慢`说的是移动的速度, 即每次移动的步长的大小
// 2. `指针`为记录变量内存地址的变量, 用它能间接访问变量的值

// 为了更直观的了解快慢指针, 请看如下`c++`demo

// 在内存中开辟容量为11个整型元素的数组存储空间

// 初始化整型快慢指针变量都记录数组第一个元素的内存地址

// 在循环里, 慢指针每次增1, 快指针每次增2

// 因为`c++`中指针占4字节即32位的16进制的内存空间, 所以慢指针记录的内存地址每次移动4个字节, 而块指针记录的内存地址每次移动8个字节(
// 注意因为是16进制, 所以快指针从`0x7ffee3c63258`到`0x7ffee3c63260`也是移动了8个字节)
// ```cpp
#include <iostream>
using namespace std;
int main (int argc, char const *argv[]) {
  int arr[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int *slowPointer = &arr[0];
  cout<<"slowPointer init point address: "<<slowPointer<<endl;
  int *fastPointer = &arr[0];
  cout<<"fastPointer init point address: "<<fastPointer<<endl;
  for (int i = 0; i < 5; ++i) {
    slowPointer++;
    fastPointer += 2;
    cout<<"i = "<<i<<endl;
    cout<<"slowPointer point address: "<<slowPointer<<endl;
    cout<<"slowPointer -> "<<*slowPointer<<endl;
    cout<<"fastPointer point address: "<<fastPointer<<endl;
    cout<<"fastPointer -> "<<*fastPointer<<endl;
  }
  return 0;
}

// slowPointer init point address: 0x7ffee3c63250
// fastPointer init point address: 0x7ffee3c63250
// i = 0
// slowPointer point address: 0x7ffee3c63254
// slowPointer -> 1
// fastPointer point address: 0x7ffee3c63258
// fastPointer -> 2
// i = 1
// slowPointer point address: 0x7ffee3c63258
// slowPointer -> 2
// fastPointer point address: 0x7ffee3c63260
// fastPointer -> 4
// i = 2
// slowPointer point address: 0x7ffee3c6325c
// slowPointer -> 3
// fastPointer point address: 0x7ffee3c63268
// fastPointer -> 6
// i = 3
// slowPointer point address: 0x7ffee3c63260
// slowPointer -> 4
// fastPointer point address: 0x7ffee3c63270
// fastPointer -> 8
// i = 4
// slowPointer point address: 0x7ffee3c63264
// slowPointer -> 5
// fastPointer point address: 0x7ffee3c63278
// fastPointer -> 10
// ```

// 说人话, 龟兔赛跑的故事大家都应该听过, 可以把乌龟🐢比作慢指针, 兔子🐇比作快指针, 下面来自灵魂画师的乌龟🐢和兔子🐇带你进入快慢指针的应用场景




// ![](https://pic.leetcode-cn.com/c321c844948c18914f9211ff58628a4d3e3d445f6004b30a04d3a85e983c462d-file_1584952697667)



// # 判断链表是否有环

// ![](https://pic.leetcode-cn.com/b58d9d4ba3fb2781a9a37b2b16fc47e75a5b541e9a122f3c06c4aa25b0d056e6-file_1584952697722)

// 无环的链表是长这样的

// ![](https://pic.leetcode-cn.com/2422c20813a46128db621470ae9da1a5dc56e498316094e34849998a5330739e-file_1584952697686)

// 有环的链表是长这样的

// ![](https://pic.leetcode-cn.com/f017f54132ee38f80c8a56d4d8734f373b9d8283db55cfa652ed3f4f2a28e2e5-file_1584952697695)



// 1. 染色标记法, 缺点: 改变了链表的结构, 若链表为只可读的则不可取, 而且此方法需开辟额外的`O(n)`存储空间记录标记信息
// ```JavaScript
var hasCycle = function(head) {
  let res = false
  while (head && head.next) {
    if (head.flag) {
      res = true
      break
    } else {
      head.flag = 1
      head = head.next
    }
  }
  return res
};
// ```
// 2. 哈希表记录法, 缺点: 哈希表需开辟额外的`O(n)`空间
// ```JavaScript
var hasCycle = function(head) {
  const map = new Map()
  while (head) {
    if (map.get(head)) {
      return true
    } else {
      map.set(head, head)
      head = head.next
    }
  }
  return false
}
// ```
// 3. 快慢指针法, 兔子与乌龟同时在头节点出发, 兔子每次跑两个节点, 乌龟每次跑一个节点, 如果兔子能够追赶到乌龟, 则链表是有环的


// ![](https://pic.leetcode-cn.com/296e94a37c5c33188fbca91213a0c35df7a4e95076b8505a389a516cc12d7cac-file_1584952697700)

// ![](https://pic.leetcode-cn.com/13a4109f745ab98f2b66e24eb6ee1fb339e874974819373ebb5b1200e6860e4d-file_1584952697705)

// ![](https://pic.leetcode-cn.com/ddccc6f39320aea3f2ec435eddbcf2879a76f90cf9d85c2681fc6e964aa6ec4a-file_1584952697711)

// ![](https://pic.leetcode-cn.com/df64c6c6de2c880008726e655507a9210bf4bcc8f6cfd4398a05354482f4b9d2-file_1584952697748)



// 因为不管有没有环, 以及进环前和进换后耗时都与数据规模成正比, 所以时间复杂度为`O(n)`, 因为只需额外的常数级存储空间记录两个指针, 所以空间复杂度为`O(1)`
// ```JavaScript
var hasCycle = function(head) {
  let slowPointer = head
  let fastPointer = head
  while (fastPointer && fastPointer.next) {
    slowPointer = slowPointer.next
    fastPointer = fastPointer.next.next
    if (fastPointer === slowPointer) {
      return true
    }
  }
  return false
}
// ```

// # 寻找链表的入环节点

// ![](https://pic.leetcode-cn.com/48ae350ab649d455770bc38238b8810c0cabe3edaf56128b43c61d947f806991-file_1584952697770)

// 此题也可用标记法和哈希表法解决, 用快慢指针法解决如下

// 还是前面的龟兔赛跑, 当兔子追到乌龟的时候, 假设有另外一只乌龟从头节点开始往前爬, 每次也只爬一个节点, 那么两只乌龟会在入环的节点相遇


// ![](https://pic.leetcode-cn.com/d4337944958803cf703b7a4bb060a8ddbeb49c7858c3745e4f716b9daee3c81b-file_1584952697768)


// ![](https://pic.leetcode-cn.com/d3fb678f3297401e49c59b351519c3916b69a4e293a2f87198bde93f1a7736af-file_1584952697771)

// 这只是一个巧合吗, 我们来分析一下

// * 假设入环之前的长度为`L`, 入环之后快慢指针第一相遇时快指针比慢指针🐢多跑了`N`圈, 每一圈的长度为`C`, 此时快指针🐰在环内离入环节点的距离为`C'`
// * 此时慢指针🐢走过的距离为: `L + C'`
// * 此时快指针🐰走过的距离为: `L + C' + N * C`
// * 因为快指针🐰的速度是慢指针🐢的两倍, 所以有: `2 * (L + C') = L + C' + N * C` 
// * 整理后得到: `(N - 1) * C + (C - C') = L`
// * 由此可知, 若此时有两个慢指针🐢同时分别从链表头结点和快慢指针第一次相遇的节点出发, 两者必然会在入环节点相遇


// ![](https://pic.leetcode-cn.com/2bb03875ff76148b86eecc9bea248201229ee5f592db8de1040120d42268e3ea-file_1584952697780)


// ![](https://pic.leetcode-cn.com/d0f29a65da49db5c968d6d8081a81cb01745bd9a5584f316b38c027f430de7ae-file_1584952697789)


// ![](https://pic.leetcode-cn.com/949ae4c8a956a04df17a0973b09a20dd6bda516a096ecb716693f3589f989ebe-file_1584952697811)


// ![](https://pic.leetcode-cn.com/fda777fe7e0c62bdecc2d2eed059b268a99c1d20734cac1b0477ceb78f344fbb-file_1584952697793)


// ![](https://pic.leetcode-cn.com/10e199d01f64b7ce863883182229aa732391922240a083ccec41352e27aa4bfe-file_1584952697802)


// ```JavaScript
var detectCycle = function(head) {
  let slowPointer = head
  let fastPointer = head
  while (fastPointer && fastPointer.next) {
    slowPointer = slowPointer.next
    fastPointer = fastPointer.next.next
    if (slowPointer === fastPointer) {
      slowPointer = head
      while (slowPointer !== fastPointer) {
        slowPointer = slowPointer.next
        fastPointer = fastPointer.next.next
      }
      return slowPointer
    }
  }
  return null
};
// ```

// # 寻找重复数

// ![](https://pic.leetcode-cn.com/71064ecc9e352acbbda366ae53c5f90ef09cbede65356fadab598427e19e183c-file_1584952697833)

// 此题暴力解法为先排序再寻找重复的数字, 注意不同`JavaScript`引擎对`sort`的实现原理不一样, `V8` 引擎 `sort` 函数对数组长度小于等于 10 的用插入排序(时间复杂度`O(n^2)`, 空间复杂度`O(1)`)，其它的用快速排序(时间复杂度`O(nlogn)`, 递归栈空间复杂度`O(logn)`), 参考[https://github.com/v8/v8/blob/ad82a40509c5b5b4680d4299c8f08d6c6d31af3c/src/js/array.js](https://github.com/v8/v8/blob/ad82a40509c5b5b4680d4299c8f08d6c6d31af3c/src/js/array.js)

// 这一题可以利用寻找链表的入环节点的思想, 把数组当成对链表的一种描述, 数组里的每一个元素的值表示链表的下一个节点的索引

// 如示例1中的`[1, 3, 4, 2, 2]`

// * 把数组索引为0的元素当成链表的头节点
// * 索引为0的元素的值为1, 表示头节点的下一个节点的索引为1, 即数组中的3
// * 再下一个节点的索引为3, 即为第一个2
// * 再下一个节点的索引为2, 即为4
// * 再下一个节点的索引为4, 即为第二个2
// * 再下一个节点的索引为2, 即为4
// * 此时形成了一个环
// * 而形成环的原因是下一节点的索引一致, 即为重复的数字


// ![](https://pic.leetcode-cn.com/714a4a6e23128ed784bf13a49c2319ea6d5e0c6f174bbbaf3a243b22dc543582-file_1584952697806)


// ![](https://pic.leetcode-cn.com/b5c4c543a4b472efb8a54323bb101d62e4f970bba5dc594fc1f15b7a12cd0c5c-file_1584952697814)


// ![](https://pic.leetcode-cn.com/2147a3b003b673ee920ca8d619d1bc26b6b72656bc61c49d7414b06b4fce3a92-file_1584952697816)


// ![](https://pic.leetcode-cn.com/c5dedb8f543c3c3d0e203dc95b186373b33f23bcbeb2ceb8fe1cda3ea8672ee6-file_1584952697820)

// ```JavaScript
var findDuplicate = function(nums) {
  let slowPointer = 0
  let fastPointer = 0
  while (true) {
    slowPointer = nums[slowPointer]
    fastPointer = nums[nums[fastPointer]]
    if (slowPointer == fastPointer) {
      let _slowPointer = 0
      while (nums[_slowPointer] !== nums[slowPointer]) {
        slowPointer = nums[slowPointer]
        _slowPointer = nums[_slowPointer]
      }
      return nums[_slowPointer]
    }
  }
};
// ```

// # 删除链表的倒数第N个元素

// ![](https://pic.leetcode-cn.com/235f4b7b6f989e7865279d0b6ef4eada1a0ee7a9db7fcc5e1f53add7482640ab-file_1584952697851)

// 要删除链表的倒数第N个元素, 需要找到其倒数第N + 1个元素, 让这个元素的next指向它的下下一个节点

// ![](https://pic.leetcode-cn.com/05c25b8d29475763ba24a0fd3bf1c63c5a120bba9bd523674a0d1128bd7b2e89-file_1584952697837)

// 此题可利用两次正向遍历链表, 或者一次正向遍历的同时记录前节点, 然后再反向遍历

// 题目的进阶要求只使用一趟扫描, 利用快慢指针可实现, 我们最终想要的乌龟和兔子的位置是这样的, 它们之间相距`N + 1`个节点, 这样乌龟所在的位置即为我们想要找的那个节点--被删除的节点前面的一个节点


// ![](https://pic.leetcode-cn.com/09bc65a963d74156e5d12fc63734901bdb2ec58659a579eadfadc3df5bb66502-file_1584952697827)

// 为方便处理头节点, 我们创建`dummy`虚拟头节点

// 让快指针🐰和慢指针🐰最开始都指向`dummy`节点

// 让快指针🐰向前移动`N + 1`个节点, 慢指针保持原地不动

// 然后两个指针以同样的速度直至快指针🐰移动至`null`

// 此时慢指针🐢移动到的位置即为被删除的指针前面的一个指针


// ![](https://pic.leetcode-cn.com/401f8b5f54d7b7e491ac2122627d7b0b78e74135ce432522d04a2fa456caf118-file_1584952697830)


// ![](https://pic.leetcode-cn.com/9e1c6fce14017e6ce78976eb914ef8ae2171d3bfcbab84089004e9e5582f608d-file_1584952697839)


// ![](https://pic.leetcode-cn.com/d21690db1c81bc63e58e6564368fe5537d91f4e3130aa8839385a18d5d04a50f-file_1584952697842)



// ![](https://pic.leetcode-cn.com/665d4c4cf5d7b4ec67fe166c6e8ccca14f10d7045353935016b0e0f09efb7d66-file_1584952697858)


// ![](https://pic.leetcode-cn.com/7af7a74910f3a9fc13e4cac281953683207399917026de9417d850f81b2efbb7-file_1584952697861)


// ```JavaScript
var removeNthFromEnd = function(head, n) {
  const dummy = new ListNode(null)
  dummy.next = head
  let slowPointer = dummy
  let fastPointer = dummy
  while (n-- > -1) {
    fastPointer = fastPointer.next
  }
  while (fastPointer !== null) {
    slowPointer = slowPointer.next
    fastPointer = fastPointer.next
  }
  slowPointer.next = slowPointer.next.next
  return slowPointer === dummy ? slowPointer.next : head
};
// ```

// # 链表的中间节点

// ![](https://pic.leetcode-cn.com/9204d694ba6a12d098daf282992107ffd472bd1a692d7f799c595b35c8ef76c1-file_1584952697863)

// ![](https://pic.leetcode-cn.com/2267b25334eb6274b60341167965100baf98f4594c5c6923089210f68db0de3c-file_1584952697866)

// 快慢指针法, 快慢指针开始时都指向头节点, 快指针每次移动一个节点, 慢指针每次移动两个节点

// 对于奇数链表, 当快指针下一节点为`null`时, 慢指针指向的节点即为所求


// ![](https://pic.leetcode-cn.com/244cd679a06d8d6894852052122d130ad1a6aa8aad75390ceee20cb1446a98b2-file_1584952697870)

// ![](https://pic.leetcode-cn.com/2b0a5dce26d7f6177e54f3b44e1fdaf94921a9ca7d8624bbd1d38bd94efb92e4-file_1584952697873)

// ![](https://pic.leetcode-cn.com/9d77effb18955d400eea3f9d7325ec23f3249111bfe71cfd2fc125e181ef33e3-file_1584952697875)

// ![](https://pic.leetcode-cn.com/7868edbf29e878e5f88afcf5ab7ea36a6d196b4e9f89cfc9bcaf36069be7a4e3-file_1584952697877)

// 对于偶数链表, 当快指针指向`null`时, 慢指针指向的节点即为所求

// ![](https://pic.leetcode-cn.com/9a3cb5c40b9d53056aa3d57ed08d58c144c628bf31ecb05bc4f0cafcb124316f-file_1584952697880)

// ![](https://pic.leetcode-cn.com/934420169c33f7ce5f7b296a39062003b8f9d583ed14adf8e875cba36ddb4411-file_1584952697884)

// ![](https://pic.leetcode-cn.com/d51f4634b075f6283613cdeba3f220465c17db90e9ce02b04c6fcfb09027fd7c-file_1584952697886)

// ![](https://pic.leetcode-cn.com/4ed978581867096ddae93c8662663ac81109a760e1db15325b7d67d36d87704d-file_1584952697890)

// ![](https://pic.leetcode-cn.com/61abe4c5ed8247075f33dc232c560a46ff0b04ce1387e19c6bfc260ca2d5d904-file_1584952697895)

// ```JavaScript
var middleNode = function(head) {
  let slowPointer = head
  let fastPointer = head
  while (fastPointer !== null && fastPointer.next !== null) {
    slowPointer = slowPointer.next
    fastPointer = fastPointer.next.next
  }
  return slowPointer
};
// ```


// # 回文链表

// ![](https://pic.leetcode-cn.com/ff6f25a517376001d213308337296646d7e45602a35cae8dd3f49dd910218893-file_1584952697898)

// 1. 把链表变成双向链表, 并从两端向中间比较

// 时间复杂度为`O(n)`, 因为要存储`prev`指针, 所以空间复杂度为`O(n)`
// ```JavaScript
var isPalindrome = function(head) {
  if (head === null) {
    return true
  } else {
    let headPointer = head
    let tailPointer = head
    while (tailPointer.next) {
      tailPointer.next.prev = tailPointer
      tailPointer = tailPointer.next
    }
    while(headPointer !== tailPointer) {
      if (headPointer.next !== tailPointer) {
        if (headPointer.val === tailPointer.val) {
          headPointer = headPointer.next
          tailPointer = tailPointer.prev
        } else {
          return false
        }
      // 考虑偶数链表
      } else {
        return headPointer.val === tailPointer.val
      }
    }
    return true
  }
};
// ```

// 2. 快慢指针
// * 慢指针🐢依次访问下一个节点, 并翻转链表
// * 快指针🐰依次访问下下一个节点, 直到快指针🐰没有下一个节点(奇数链表)或者快指针指向`null`(偶数链表), 此时已完成了前半截链表的翻转
// * 依次比较前半截链表和后半截链表节点的值

// 对于奇数链表:

// ![](https://pic.leetcode-cn.com/cb1a253142ebef3f7af3a2d000691ef5376fbb327db39bd72c38d0021ade7428-file_1584952697900)


// ![](https://pic.leetcode-cn.com/2d8e7e0aacc2346bcc75ce8cbd435281e4db7c766ee55dc3bb4f0565431be4d6-file_1584952697902)


// ![](https://pic.leetcode-cn.com/8ed2425ca01c0c8c5cd691a445a6cdc052dbdc36f164fb948ac92c5fde0dc791-file_1584952697904)

// 对于偶数链表:

// ![](https://pic.leetcode-cn.com/d6b3c64c451d2ef8a5b27a0cce868fca8e60ed518560a833d80f550f4cb9eb8f-file_1584952697907)

// ![](https://pic.leetcode-cn.com/c8f3bec9c6ce2125ae62cc7519f7dff7dd5d24035672d3046e79b9a0f9d059d7-file_1584952697910)

// ![](https://pic.leetcode-cn.com/b13e92c81167cb880ea65b894771b76e734b5cde9bb278ee7cae1391aa10cecb-file_1584952697913)


// ![](https://pic.leetcode-cn.com/d1f53eac561e67553695c54923b45193fd40cad0139841540acee906059ed508-file_1584952697927)


// ![](https://pic.leetcode-cn.com/992c11e7094349e83003edf9b497a5dfd5656177b31e2e4ff5cfbba888b63b9c-file_1584952697930)

// 时间复杂度`O(n)`, 空间复杂度`O(1)`

// ```JavaScript
var isPalindrome = function(head) {
  if (head === null) {
    return true
  } else if (head.next === null) {
    return true
  } else {
    let slowPointer = head
    let fastPointer = head
    let _head = null
    let temp = null
    // 找到中间节点, 并翻转前半截链表,
    // 让_head指向翻转后的前半截链表的头部,
    // 让slow指向后半截链表的头节点
    while (fastPointer && fastPointer.next) {
      _head = slowPointer
      slowPointer = slowPointer.next
      fastPointer = fastPointer.next.next
      _head.next = temp
      temp = _head
    }
    // 奇数链表跳过最中间的节点
    if (fastPointer) {
      slowPointer = slowPointer.next
    }
    while (_head) {
      if (_head.val !== slowPointer.val) {
        return false
      }
      _head = _head.next
      slowPointer = slowPointer.next
    }
    return true
  }
};
// ```

// # 快乐数

// ![](https://pic.leetcode-cn.com/c83b0a428bcca5cd5b1bed49077e609081e58258ba7da44b4fcc9dd4040974fc-file_1584952697933)
// 1. 循环并缓存每次获取位的平方和, 如果已缓存过, 就退出循环, 判断退出循环后是否为1, 缺点: 需开辟`O(n)`的存储空间
// ```JavaScript
var isHappy = function(n) {
  const memory = {}
  while (n !== 1) {
    function getBitSquareSum (n) {
      let sum = 0
      while (n !== 0) {
        const bit = n % 10
        sum += bit * bit
        n = parseInt(n / 10)
      }
      return sum
    }
    n = getBitSquareSum(n)
    if (memory[n] === undefined) {
      memory[n] = 1
    } else {
      break
    }
  }
  return n === 1
};
// ```
// 2. 慢指针🐢获取一次每位的平方和, 快指针🐰获取两次每位的平方和, 当两个指针值一样时判断其是否为1

// 对于19这个数, 快慢指针会在每位的平方和为1时相遇, 兔子会在1处等乌龟

// ![](https://pic.leetcode-cn.com/cfe6aa541e16b256c5a1b44f88f63034bf450012b1076c1e7fd824d1ff68554b-file_1584952697936)

// ![](https://pic.leetcode-cn.com/46363c68541828a9ba4b62219c1910e27cff1887813cee00f04361af6c13fa78-file_1584952697940)

// ![](https://pic.leetcode-cn.com/f7580f0a669ba20981fe02d28830a586281f908258eb95da1518e1050167d6cd-file_1584952697944)

// ![](https://pic.leetcode-cn.com/e4f0a7db937503c2fca92f1deb286e6c1f8da0b026085aef384e6ae68765b85e-file_1584952697947)

// ![](https://pic.leetcode-cn.com/dc962b2c39bd7f6a85aa0f782361784a1d53f07fe8c96f115b1f8b1e6beacc5c-file_1584952697954)

// ![](https://pic.leetcode-cn.com/6c3abacf334ea52d12b04a2fee07a95cbbb5a89065cc6bc8d2d5e79e52ed431b-file_1584952697960)


// 对于37这个数, 对其反复的求每位的平方和会进入循环, 而且进入循环时其值不为1

// ![](https://pic.leetcode-cn.com/b0e70cb78eb3071451746e77de25e9e198abc1060532cace2ccafc662ef4c6af-file_1584952697963)

// ![](https://pic.leetcode-cn.com/1cdcc1a8eebe3987aefa888d16e74bf43723d11a25b35b0ed5ca038361236369-file_1584952697966)

// ![](https://pic.leetcode-cn.com/b258da6135a2244e6d878c99c17e473e1a7ef50fad62d8c0e586f52c33393c92-file_1584952697969)

// ![](https://pic.leetcode-cn.com/5bc83eb36a65fb6ed2b84db4132a038157015f5e484bff0b311bd4f96d5df56d-file_1584952697972)

// ![](https://pic.leetcode-cn.com/805ed96cd0fb9bb3f40a8bfee0b761f9a751aed4273888886ba7374cda05a819-file_1584952697975)

// ![](https://pic.leetcode-cn.com/1e5891e16a56cab4465b8fe0a7a7e7fd8990eec4828c7a3c56b575f39080798f-file_1584952697980)

// ![](https://pic.leetcode-cn.com/4e9eb17d5c70786067bc1c242ed51c03310358413ab078543269b43f7a6228ea-file_1584952697983)

// ![](https://pic.leetcode-cn.com/04564775e2958cfe6ecaf93e5fc99be7ffdc92852274bb14588ca3bc5765214d-file_1584952697989)

// ![](https://pic.leetcode-cn.com/34c0bfc030006503fcbcf5ae3ae24241b2696e5815eb6c9ac74586a28c2a2ece-file_1584952697993)

// ![](https://pic.leetcode-cn.com/3ba03c495f1ade1906f4436f3d6630ffc773c9f217e291f0d83a395ca1b49671-file_1584952698001)



// ```JavaScript
var isHappy = function (n) {
  let slowPointer = n
  let fastPointer = n
  function getBitSquareSum (n) {
    let sum = 0
    while (n !== 0) {
      const bit = n % 10
      sum += bit * bit
      n = parseInt(n / 10)
    }
    return sum
  }
  do {
    slowPointer = getBitSquareSum(slowPointer)
    fastPointer = getBitSquareSum(getBitSquareSum(fastPointer))
  } while (slowPointer !== fastPointer)
  return slowPointer === 1
}
// ```

// # 总结
// 在一些场景, 如链表数据结构和判断循环, 利用快慢指针创造的差值, 可节省内存空间, 减少计算次数

// <br>
// 快慢指针, 一对快乐的指针, just be happy!

// ![](https://pic.leetcode-cn.com/598dd26c4abf2fef16fdc0f763d50882aca1b71b3c055c7445906edc2e065493-file_1584952698003)


// 原文在掘金, [https://juejin.im/post/5e64a20ff265da570a5d5633](https://juejin.im/post/5e64a20ff265da570a5d5633), 欢迎点赞、关注和来撩😎