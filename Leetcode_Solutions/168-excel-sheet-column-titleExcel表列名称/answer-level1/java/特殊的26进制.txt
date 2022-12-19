1. 该题的实质是10进制转26进制，但是这个26进制有点特殊，一般26进制是指 0-25，但是在这里，26进制指的是 1-26。
2. 由于没有 0 的存在，因此在处理26的倍数的时候，需要手动消除 0，换上 26 来替代 0 的位置
3. 以 52 为例：
- 52 / 26 = 2，余数是 0 
- 则使用 26 来替代 0 所在的位置，即 商 为 1，余数为 26
- 返回的结果则是 AZ
```
class Solution {
  public String convertToTitle(int n) {
    StringBuilder stringBuilder=new StringBuilder();
    char c=' ';
    while (n>0){
      if (n%26==0){
        stringBuilder.append('Z');
        n=n/26-1;
      }else {
        c = (char) ((n % 26) + 64);
        stringBuilder.append(c);
        n = n / 26;
      }
    }
    return String.valueOf(stringBuilder.reverse());
  }
}
```
