- 相等的属于一个集合
- 不相等的就需要判断不属于一个集合
- 先把相等的都归到一个
- 再判断不相等的是否不属于一个集合
```
var equationsPossible = function(equations) {
  class DSU {
    constructor(N = 26) {
      this.nodes = new Array(N);
      for (let i = 0; i < N; ++i) {
        this.nodes[i] = i;
      }
    }
  
    parent(i) {
      if (this.nodes[i] !== i) return this.parent(this.nodes[i])
      return this.nodes[i];
    }
  
    union(a, b) {
      this.nodes[this.parent(a)] = this.parent(b)
    }
  }   
  let dsu = new DSU(26);
  equations.forEach(el => {
    if (el[1] === '=') {
      dsu.union(el[0].codePointAt() - 97, el[2].codePointAt() - 97)
    }
  })

  return !(equations.find(el => {
    return el[1] === '!' && dsu.parent(el[0].codePointAt() - 97) === dsu.parent(el[2].codePointAt() - 97)
  }))
};
```
