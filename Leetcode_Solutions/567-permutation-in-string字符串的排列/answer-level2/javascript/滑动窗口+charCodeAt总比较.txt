```js
var checkInclusion = function(s1: string, s2: string): boolean {
  if (s2.length < s1.length) {
    return false;
  }
  let s1CodeTotal: number = 0;
  let s2CodeTotal: number = 0;
  const s1Array: number[] = new Array(26).fill(0);
  const s2Array: number[] = new Array(26).fill(0);
  for (let i = 0; i < s1.length; i++) {
    s1CodeTotal += s1[i].charCodeAt(0);
    s2CodeTotal += s2[i].charCodeAt(0);
    s1Array[getArrayIndex(s1, i)]++;
    s2Array[getArrayIndex(s2, i)]++;
  }
  for (
    let left = 0, right = s1.length - 1;
    right < s2.length;
    left++, right++
  ) {
    if (left !== 0) {
      s2CodeTotal += s2[right].charCodeAt(0) - s2[left - 1].charCodeAt(0);
      s2Array[getArrayIndex(s2, left - 1)]--;
      s2Array[getArrayIndex(s2, right)]++;
    }
    if (s1CodeTotal === s2CodeTotal) {
      if (isMatch()) {
        return true;
      }
    }
  }

  return false;

  function isMatch(): boolean {
    for (let i = 0; i < 26; i++) {
      if (s1Array[i] !== s2Array[i]) {
        return false;
      }
    }
    return true;
  }

  function getArrayIndex(s: string, i: number): number {
    return s[i].charCodeAt(0) - 97;
  }
};
```