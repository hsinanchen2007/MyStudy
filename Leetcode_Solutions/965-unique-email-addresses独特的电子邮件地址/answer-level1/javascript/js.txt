
1.去重
2.去  .
3.去 +号到 @之间的

var numUniqueEmails = function(emails) {
   return [...new Set(emails.map(i => {
      return (i.split('@')[0].replace(/\./g, '') + '@'+i.split('@')[1]).replace(/\+.*(?=@)/, '')
    }))].length
};
