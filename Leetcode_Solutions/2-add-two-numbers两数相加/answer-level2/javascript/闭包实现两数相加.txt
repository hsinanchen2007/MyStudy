var addTwoNumbers = function(l1, l2) {
  handleNode = () => {
    // 记录上一次余数
    let beforeNum = 0;

    return (node1, node2) => {
      const val = (node1 ? node1.val : 0) + (node2 ? node2.val : 0);
      let newVal = (val % 10) + beforeNum;
      // 加余数大于 10 的情况
      if (newVal >= 10) {
        beforeNum = parseInt(newVal / 10);
        newVal = newVal % 10;
      } else {
        beforeNum = parseInt(val / 10);
      }

      // 共享存储空间
      const result = node1 ? node1 : node2 ? node2 : {};
      result.val = newVal;
      if ((node1 && node1.next) || (node2 && node2.next) || beforeNum !== 0) {
        result.next = handler(node1 ? node1.next : null, node2 ? node2.next : null);
      }
      return result;
    };
  };

  const handler = handleNode();
  return handler(l1, l2);
};