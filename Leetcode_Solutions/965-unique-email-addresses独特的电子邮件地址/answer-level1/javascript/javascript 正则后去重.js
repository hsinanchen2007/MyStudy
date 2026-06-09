正则去除本地+后面的所有内容和去掉.
.replace(/(\+.*)|\./g,"");
```
    var numUniqueEmails = function(emails) {
        let res = [];
        let base = [];
        let newKey = "";
        for(let i=0;i<emails.length;i++){
            base = emails[i].split('@');
            newKey = base[0].replace(/(\+.*)|\./g,"")+"@"+base[1];
            if(res.indexOf(newKey) == -1){
                res.push(newKey);
            }
        }
        return res.length;
    };
```
