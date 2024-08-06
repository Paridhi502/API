[POST] /api/signup

Request Data : {
"username": "example_user",
"password": "example_password",
"email": "user@example.com"
 }

Response Data : {
"status": "Account successfully created",
"status_code": 200,
"user_id": "123445"
}}
[POST] /api/login
Request Data : {
"username": "example_user",
"password": "example_password"
}

For successful login
Response Data : {
"status": "Login successful",
"status_code": 200,
"user_id": "12345",
"access_token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9"
}
Response Data: {
"status": "Incorrect username/password provided. Please retry",
"status_code": 401
}

Request Data : {
"category": "SUV",
"model": "BMW Q3"
"number_plate": "KA1234",
"current_city": "bangalore",
"rent_per_hr": 100,
"rent_history": []
}
Response Data : {
"message": "Car added successfully",
"car_id": "12345",
"status_code": 200
}

[GET] /api/car/get-rides?origin={origin}&destination={dest}&category={cat}&required_hours={rh}
Request Data : {}
Params: {
"origin": str,
"dest": str,
"cat": str,
"rh": int
}

Response Data : [
{
"car_id": "1234",
"category": "SUV",
"model": "BMW Q3"
"number_plate": "KA1234",
"current_city": "bangalore",

"rent_per_hr": 100,
"rent_history": [
{
"origin": "bangalore",
"destination": "mumbai",
"amount": 10000
}
],
"total_payable_amt": 1000
},
{
"car_id": "5678",
"category": "SUV",
"model": "BMW Q3"
"number_plate": "KA1234",
"current_city": "bangalore",
"rent_per_hr": 100,
"rent_history": [],
"total_payable_amt": 1000
}
]
[POST] /api/car/rent
Headers : {
"Authorization": "Bearer {token}"
}

Request Data : {
"car_id": "12345",
"origin": "mumbai",
"destination": "bangalore",
"hours_requirement": 10
}
Response Data : {
"status": "Car rented successfully",
"status_code": 200
"rent_id": "54321",
"total_payable_amt": 1000
}

Response Data : {
"status": "No car is avialable at the moment",
"status_code": 400
}

[POST] /api/car/update-rent-history
Headers : {
"Authorization": "Bearer {token}" //Has to be admin's token
}

Request Data : {
"car_id": "12345",
"ride_details": {
"origin": "mumbai",
"destination": "bangalore",
"hours_requirement": 10
}
}

Response Data : {
"status": "Car's rent history updated successfully",
"status_code": 200
