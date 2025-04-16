const form = document.getElementById("register-form");

form.addEventListener("submit", function(event) {
  event.preventDefault();

  const username = document.getElementById("username").value;
  const password = document.getElementById("password").value;

  localStorage.setItem("user", JSON.stringify({ username, password }));

  alert("Cadastro realizado com sucesso!");
  window.location.href = "login.html";
});

// Alternar dark mode
const toggleDark = document.getElementById("toggle-dark");

toggleDark.addEventListener("click", () => {
  document.body.classList.toggle("dark-mode");
});
