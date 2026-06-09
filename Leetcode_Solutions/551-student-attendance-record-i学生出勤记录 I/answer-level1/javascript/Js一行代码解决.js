```
var checkRecord = function(s) {
  return Array.from(s).filter(i => i === 'A').length <=1 && !s.includes('LLL')
};
```
