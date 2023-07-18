class BankAccount:
    def __init__(self, account_number, initial_balance = 0):
        self.account_number = account_number
        self.balance = initial_balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"{amount} submitted successfully")
        else:
            print("Invalid Amount! Please Enter a positive number.")

    def withdraw(self, amount):
        if amount >= 0:
            self.balance -= amount
            print(f"{amount} has been withdrawn from your account")
        else:
            print("Invalid Amount! Please Enter a Positive Amount")

    def check_balance(self):
        print(f"Your current balance is {self.balance}")

    def run_transactions(self):
        while True:
            print("1. Deposit Money")
            print("2. Withdraw")
            print("3. Check Balance")
            print("4. Quit")
            choice = input("Enter Your Choice = ")

            if choice == "1":
                amount = float(input("Enter the amount you want to deposit = "))
                self.deposit(amount)

            elif choice == "2":
                amount = float(input("Enter the amount that you want to withdraw = "))
                self.withdraw(amount)

            elif choice == "3":
                self.check_balance()

            elif choice == "4":
                print("Thanks For Using our Application")
                break
            else:
                print("Invalid Choice!")

account_number = input("Enter Your Account Number = ")
initial_balance = float(input("Enter Your Initial Balance = "))
bank_account = BankAccount(account_number, initial_balance)

bank_account.run_transactions()


