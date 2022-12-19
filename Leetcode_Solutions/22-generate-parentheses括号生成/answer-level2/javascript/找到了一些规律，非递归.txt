
如果将所有'('按序换为1，3，5…的奇数序列，将所有')'按序换为2，4，6…的偶数序列，得到的数字序列，存在这样的规律：以1起始，奇数大于左边的任意数，偶数大于左边的任意偶数。
所以在生成新序列时，以'('起始 ，下一个数必须小于等于2n；若是偶数，需要当前序列最大偶数小于最大奇数，然后加入')'，并让该序列的最大偶数+2；若是奇数，则加入'('。当序列长度为2n时退出。
代码如下，时间复杂度O(n*m)，m是最终生成的序列个数，应该和n有数学关系，但我不确定具体关系。
```javascript []
var generateParenthesis = function(n) {
  if (n === 0) return [];
  if (n === 1) return ['()'];
  let result = ['('], sequenceQuote = [[1, 0]];
  let length = 1;
  let limit = 2 * n;
  while (length < limit) {
    let tempResult = [], tempSequenceQuote = [];
    for (let i = 0; result[i]; i++) {
      for (let j = 0; j < 2; j++) {
        let quotes = [...(sequenceQuote[i])];
        if (quotes[j] + 2 > limit) {
          continue;
        }
        if (j === 1 && quotes[j] > quotes[0]) {
          break;
        }
        let newSequence = result[i] + (j === 0 ? '(' : ')');
        tempResult.push(newSequence);
        quotes[j] += 2;
        tempSequenceQuote.push(quotes);
      }
    }
    result = tempResult;
    sequenceQuote = tempSequenceQuote;
    length++;
  }
  return result;
};
```