// Login existente
const loginForm = document.getElementById("login-form"); 

loginForm.addEventListener("submit", function(event) {
  event.preventDefault();

  const username = document.getElementById("login-username").value;
  const password = document.getElementById("login-password").value;

  const storedUser = JSON.parse(localStorage.getItem("user"));

  if (storedUser && username === storedUser.username && password === storedUser.password) {
    alert("Login bem-sucedido!");
    // window.location.href = "home.html";
  } else {
    alert("Usuário ou senha incorretos.");
  }
});

// Dark mode toggle
const toggle = document.getElementById("dark-toggle");

toggle.addEventListener("click", () => {
  document.body.classList.toggle("dark-mode");
});
