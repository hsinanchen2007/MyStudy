- visited[num]表示num是否被使用
- 每次循环都通过visited去找下一个符合要求的数字 找到后索引值加一
- 一个for循环中每个数字只使用一次  使用完成以后需要释放 即visited[num] = false
```
var countArrangement = function(N) {
  let visited = new Array(N+1).fill(false);
  let res = 0;
  let dfs = function(index) {
    if (index > N) {
      ++res;
      return;
    }
    for (let num = 1; num <= N; ++num) {
      if (!visited[num] && (num % index === 0 || index % num === 0)) {
        visited[num] = true;
        dfs(index+1)
        visited[num] = false;
      }
    }
  } 
  dfs(1)
  return res;
};
```
