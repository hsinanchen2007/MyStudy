var permutation = function(s, prefix, res) {
  if (!res) { res = []; }
  if (!prefix) { prefix = '';};
  let rest = s;
  [...prefix].forEach((letter)=> {
    rest = rest.replace(letter, '')
  })
  if (!rest) {
      if (res.indexOf(prefix) === -1) {
        res.push(prefix);
      }
      return ;
  }
  for (let i=0; i< rest.length; i++) {
      permutation(s, prefix+rest[i], res);
  }
  return res;
};