# SE 211 01 Term Project Hospital Management Systems 

#The Architectural Point of view

The code above defines two structures, Patient and Hospital, and uses them to represent patients and hospitals in the hospital management system. The Patient structure contains information about a single patient, including their name, age, and diagnosis. The Hospital structure contains an array of Patient structures and an integer representing the number of patients currently in the hospital.

The code also defines several functions that operate on the Hospital and Patient structures. The addPatient() function adds a new patient to the hospital, the dischargePatient() function discharges a patient from the hospital, and the printHospital() function prints the current state of the hospital.

From an architectural point of view, the code uses a simple object-oriented design to represent the entities and operations involved in a hospital management system. The Patient and Hospital structures act as classes, and the functions act as methods that operate on instances of these classes. This allows for a clear and modular representation of the problem domain, with each class and function representing a specific aspect of the hospital management system Overall, the code represents a simple and straightforward implementation of a hospital management system, using structures and functions in C to organize and manipulate the data.
