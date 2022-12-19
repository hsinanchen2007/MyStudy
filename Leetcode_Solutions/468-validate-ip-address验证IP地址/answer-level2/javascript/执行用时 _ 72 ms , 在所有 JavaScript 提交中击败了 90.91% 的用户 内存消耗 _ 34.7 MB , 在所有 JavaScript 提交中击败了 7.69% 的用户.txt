var validIPAddress = function (IP) {
  var flag = true;
  var iPV4 = IP.split('.');
  if (iPV4.length === 4) {
    //是ipv4
    var arr = iPV4.filter(item => {
      var temp1 = [...item].every(value => {
        return value.charCodeAt() >= 48 && value.charCodeAt() <= 57
      })
      if (item.length != 1) {
        if (item[0] == '0') {
          flag = false;
        }
      }
      return flag && item.length !== 0 && temp1 && Number(item) >= 0 && Number(item) <= 255;
    })
    console.log(arr)
    if (arr.length !== 4) {
      return "Neither"
    } else {
      return "IPv4"
    }
  } else {
    var ipv6 = IP.split(':');  //65---90
    if (ipv6.length == 8) {
      //可能是ipv6
      var arrtemp = ipv6.filter(item => {

        var temp = [...item.toUpperCase()].every(value => value.charCodeAt() >= 48 && value.charCodeAt() <= 57 || value.charCodeAt() >= 65 && value.charCodeAt() <= 70)
        return item.length !== 0 && temp && item.length <= 4
      })
      if (arrtemp.length === 8) {
        return "IPv6"
      } else {
        return "Neither"
      }
    } else {
      return "Neither"
    }
  }
};