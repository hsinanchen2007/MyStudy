var camelMatch = function(queries, pattern) {
  var reg = '^([a-z]*)'
  for(var i=0;i<pattern.length;i++){
    reg = reg + pattern[i]+'([a-z]*)'
  }
  reg = reg +'$'
  var regexp = new RegExp(reg)
  return queries.map(v=>regexp.test(v))
};