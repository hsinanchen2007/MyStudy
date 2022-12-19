```
const checkInclusion = function(s1, s2) {
  const l1 = s1.length
  const l2 = s2.length
  const v1 = new Vector()
  const v2 = new Vector() 
  for (let i = 0; i < l1; i++) {
    v1.add(s1[i])
  }
  for (let j = 0; j < l2; j++) {
    v2.add(s2[j])
    if (j >= l1) {
      v2.delete(s2[j - l1])
    }
    if (v1.equals(v2)) return true
  }
  return false
};

class Vector {
  constructor() {
    this.map = Array.from(Array(26)).map(() => 0)
  }
  add(char) {
    this.map[char.charCodeAt() - 97]++
  }
  delete(char) {
    this.map[char.charCodeAt() - 97]--
  }
  equals(vector) {
    return this.map.toString() === vector.map.toString()
  }
}
```