# Supermarket Management System in C++

A **Supermarket Management System** built using C++ to efficiently handle product inventory, process customer orders, and generate bills. The system provides separate functionalities for **Admin** and **Customers**, making it suitable for both product management and customer transactions.

## Features

### Admin Functionalities:
- **Add New Products**: Admins can add new products to the system with details like product name, price, and available quantity.
- **Modify Existing Products**: Admins can update the product's price and quantity.
- **Delete Products**: Admins can remove products from the system.

### Customer Functionalities:
- **View Products**: Customers can view the list of available products, including the price and quantity of each item.
- **Add Products to Cart**: Customers can add desired products to their shopping cart by entering the product ID and quantity.
- **Generate Bill**: The system calculates the total cost of the selected items and provides a detailed bill.

### Product Management:
- Each product has the following properties:
  - **Product ID** (Unique Identifier)
  - **Product Name**
  - **Price**
  - **Quantity** (Stock Available)

### Order Processing:
- Customers can select multiple products and specify the quantity.
- The system automatically calculates the total bill based on the selected items.

## Example Usage

### Available Products:
| Product ID | Product Name | Price (Rs.) | Stock (Quantity) |
|------------|--------------|-------------|------------------|
| 101        | Milk         | 50          | 100              |
| 102        | Bread        | 20          | 200              |
| 103        | Eggs         | 5           | 500              |

### Customer Transaction:

1. **Product Selection**  
   - Customer enters Product ID: **101** (Milk)  
     - **Quantity**: 2  

   - Customer enters Product ID: **102** (Bread)  
     - **Quantity**: 1  

2. **Bill Summary**:
    ```
    1. Milk (2 units)  - Rs. 100
    2. Bread (1 unit)  - Rs. 20
    ----------------------------
    Total Amount: Rs. 120
    ```
