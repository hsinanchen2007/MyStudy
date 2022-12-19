用JavaScript来说应该不难，一行代码就可以搞定
var isMatch = function(s, p) {
  return new RegExp(['^', ...p, '$'].join('')).test(s);
}