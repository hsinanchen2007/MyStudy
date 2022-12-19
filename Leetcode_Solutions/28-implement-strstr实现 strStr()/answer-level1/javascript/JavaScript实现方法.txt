# 主要使用的思想还是获取到彼此第一个开始的字符串，然后根据needle的长度为基准，进行截取haystack所在字符串的位置长度比较，如果相等，那么就返回下标位置，否则跳过执行，找不到最后就返回-1，速度上去了，但是内存的消耗变多了
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
     if (!needle) return 0
     let count = 0, mark = -1;
     for (let i = 0; i < haystack.length; i++) {
          if (haystack.charAt(i) === needle.charAt(count)) {
               if (haystack.substring(i, i + needle.length) === needle) {
                    return i
               }
               continue;
          }
     }
     return -1
};
