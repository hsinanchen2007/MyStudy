SELECT DISTINCT stock_name, SUM(IF(operation = 'Sell', price, -price)) AS capital_gain_loss
FROM Stocks
GROUP BY 1